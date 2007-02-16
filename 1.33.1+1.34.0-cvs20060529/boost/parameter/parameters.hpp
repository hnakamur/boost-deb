// Copyright David Abrahams, Daniel Wallin 2003. Use, modification and 
// distribution is subject to the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETERS_031014_HPP
#define BOOST_PARAMETERS_031014_HPP

#include <boost/detail/is_xxx.hpp>

#include <boost/mpl/lambda.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/pair.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_reference.hpp>

#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_shifted.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_shifted_params.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/cat.hpp>

#include <boost/parameter/aux_/arg_list.hpp>
#include <boost/parameter/aux_/yesno.hpp>
#include <boost/parameter/aux_/void.hpp>
#include <boost/parameter/aux_/default.hpp>
#include <boost/parameter/aux_/unwrap_cv_reference.hpp>
#include <boost/parameter/aux_/tagged_argument.hpp>
#include <boost/parameter/aux_/tag.hpp>
#include <boost/parameter/aux_/template_keyword.hpp>
#include <boost/parameter/config.hpp>

namespace boost {

template<class T> class reference_wrapper;

namespace parameter {

namespace aux { struct use_default {}; }

// These templates can be used to describe the treatment of particular
// named parameters for the purposes of overload elimination with
// SFINAE, by placing specializations in the parameters<...> list.  In
// order for a treated function to participate in overload resolution:
//
//   - all keyword tags wrapped in required<...> must have a matching
//     actual argument
//
//   - The actual argument type matched by every keyword tag
//     associated with a predicate must satisfy that predicate
//
// If a keyword k is specified without an optional<...> or
// required<...>, wrapper, it is treated as though optional<k> were
// specified.
//
// If a keyword k is specified with unnamed<...>, that keyword
// will be automatically deduced from the argument list.
//
template <class Tag, class Predicate = aux::use_default>
struct required
{
    typedef Tag key_type;
    typedef Predicate predicate;
};

template <class Tag, class Predicate = aux::use_default>
struct optional
{
    typedef Tag key_type;
    typedef Predicate predicate;
};

template <class Tag, class Predicate>
struct unnamed
{
    typedef Tag key_type;
    typedef Predicate predicate;
};

namespace aux
{
  // Defines metafunctions, is_required and is_optional, that
  // identify required<...>, optional<...> and unnamed<...> specializations.
  BOOST_DETAIL_IS_XXX_DEF(required, required, 2)
  BOOST_DETAIL_IS_XXX_DEF(optional, optional, 2)
  BOOST_DETAIL_IS_XXX_DEF(unnamed, unnamed, 2)

  //
  // key_type, has_default, and predicate --
  //
  // These metafunctions accept a ParameterSpec and extract the
  // keyword tag, whether or not a default is supplied for the
  // parameter, and the predicate that the corresponding actual
  // argument type is required match.
  //
  // a ParameterSpec is a specialization of either keyword<...>,
  // required<...>, optional<...> or unnamed<...>
  //

  // helper for key_type<...>, below.
  template <class T>
  struct get_key_type
  { typedef typename T::key_type type; };

  template <class T>
  struct key_type
    : mpl::eval_if<
          mpl::or_<
              is_optional<T>
            , is_required<T>
            , is_unnamed<T>
          >
        , get_key_type<T>
        , mpl::identity<T>
      >
  {
  };

  template <class T>
  struct has_default
    : mpl::not_<is_required<T> >
  {};

  // helper for get_predicate<...>, below
  template <class T>
  struct get_predicate_or_default
  {
      typedef T type;
  };

  template <>
  struct get_predicate_or_default<use_default>
  {
      typedef mpl::always<mpl::true_> type;
  };

  // helper for predicate<...>, below
  template <class T>
  struct get_predicate
  {
      typedef typename
          get_predicate_or_default<typename T::predicate>::type
      type;
  };

  template <class T>
  struct predicate
    : mpl::eval_if<
         mpl::or_<
              is_optional<T>
            , is_required<T>
            , is_unnamed<T>
          >
        , get_predicate<T>
        , mpl::identity<mpl::always<mpl::true_> >
      >
  {
  };


  // Converts a ParameterSpec into a specialization of
  // parameter_requirements.  We need to do this in order to get the
  // key_type into the type in a way that can be conveniently matched
  // by a satisfies(...) member function in arg_list.
  template <class ParameterSpec>
  struct as_parameter_requirements
  {
      typedef parameter_requirements<
          typename key_type<ParameterSpec>::type
        , typename predicate<ParameterSpec>::type
        , typename has_default<ParameterSpec>::type
      > type;
  };

  template <class T>
  struct is_named_argument
    : mpl::or_<
          is_template_keyword<T>
        , is_tagged_argument<T>
      >
  {};
  
  // Labels Arg with default keyword tag DefaultTag if it is not
  // already a tagged_argument. If an unnamed spec that matches
  // Arg exists in UnnamedList, labels Arg with that spec's
  // keyword tag.
  template <class Positional, class Arg, class UnnamedList, class TagFn>
  struct as_tagged_argument
    : mpl::eval_if<
          is_named_argument<Arg>
        , mpl::identity<mpl::pair<Arg, UnnamedList> >
        , mpl::apply_wrap3<UnnamedList, Arg, Positional, TagFn>
      >
  {};
  
#if BOOST_WORKAROUND(BOOST_MSVC, < 1300)  // ETI workaround
  template <>
  struct as_tagged_argument<int,int,int,int>
  {
      typedef int type;
  };
#endif

  // Returns mpl::true_ iff the given ParameterRequirements are
  // satisfied by ArgList.
  template <class ArgList, class ParameterRequirements>
  struct satisfies
  {
#if BOOST_WORKAROUND(BOOST_MSVC, == 1310)
      // VC7.1 can't handle the sizeof() implementation below,
      // so we use this instead.
      typedef typename mpl::apply_wrap2<
          typename ArgList::binding
        , typename ParameterRequirements::keyword
        , void_
      >::type bound;

      typedef typename mpl::eval_if<
          is_same<bound, void_>
        , typename ParameterRequirements::has_default
        , mpl::apply1<
              typename ParameterRequirements::predicate
            , typename remove_reference<bound>::type
          >
      >::type type;
#else
      BOOST_STATIC_CONSTANT(
          bool, value = (
              sizeof(
                  aux::to_yesno(
                      ArgList::satisfies((ParameterRequirements*)0)
                  )
              ) == sizeof(yes_tag)
          )
      );

      typedef mpl::bool_<satisfies::value> type;
#endif
  };

  // Returns mpl::true_ if the requirements of the given ParameterSpec
  // are satisfied by ArgList.
  template <class ArgList, class ParameterSpec>
  struct satisfies_requirements_of
    : satisfies<
          ArgList
        , typename as_parameter_requirements<ParameterSpec>::type
      >
  {};

  // Helper for make_partial_arg_list, below.  Produce an arg_list
  // node for the given ParameterSpec and ArgumentType, whose tail is
  // determined by invoking the nullary metafunction TailFn.
  template <class ParameterSpec, class ArgumentType, class TagFn, class TailFn>
  struct make_arg_list
  {
      template <class UnnamedList>
      struct apply
      {
          typedef typename as_tagged_argument<
              ParameterSpec,ArgumentType,UnnamedList,TagFn
          >::type tagged_result;

          typedef arg_list<
              typename mpl::first<tagged_result>::type
            , typename mpl::apply_wrap1<
                  TailFn, typename mpl::second<tagged_result>::type
              >::type 
          > type;
      };
  };

  // Just like make_arg_list, except if ArgumentType is void_, the
  // result is empty_arg_list.  Used to build arg_lists whose length
  // depends on the number of non-default (void_) arguments passed to
  // a class template.
  template <
      class ParameterSpec
    , class ArgumentType
    , class TagFn
    , class TailFn
  >
  struct make_partial_arg_list
  {
      template <class UnnamedList>
      struct apply
      {
        typedef typename mpl::eval_if<
              is_same<ArgumentType, void_>
            , mpl::identity<empty_arg_list>
            , mpl::apply_wrap1<
                  make_arg_list<ParameterSpec, ArgumentType, TagFn, TailFn>
                , UnnamedList
              >
        >::type type;
      };
  };

  // Generates:
  //
  //   make<
  //       parameter_spec#0, argument_type#0
  //     , make<
  //           parameter_spec#1, argument_type#1
  //         , ... mpl::identity<aux::empty_arg_list>
  //    ...>
  //   >
#define BOOST_PARAMETER_make_arg_list(z, n, names)      \
      BOOST_PP_SEQ_ELEM(0,names)<                       \
          BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(1,names), n),  \
          BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(2,names), n),  \
          BOOST_PP_SEQ_ELEM(3,names),

#define BOOST_PARAMETER_right_angle(z, n, text) >

#define BOOST_PARAMETER_build_arg_list(n, make, parameter_spec, argument_type, tag) \
  BOOST_PP_REPEAT(                                                                  \
      n, BOOST_PARAMETER_make_arg_list, (make)(parameter_spec)(argument_type)(tag)) \
  mpl::always<aux::empty_arg_list>                                                  \
  BOOST_PP_REPEAT(n, BOOST_PARAMETER_right_angle, _)

  // Terminates an unnamed_list (below).
  struct empty_unnamed_list
  {
      template <class Arg, class Positional, class TagFn>
      struct apply
      {
          // No unnamed predicate matched Arg, so we tag Arg with
          // the DefaultTag.

          BOOST_MPL_ASSERT_NOT((is_unnamed<Positional>));

          typedef mpl::pair<
              typename mpl::apply_wrap2<
                  TagFn
                , typename key_type<Positional>::type
                , Arg
              >::type
            , empty_unnamed_list
          > type;
      };
  };

  // Used by as_tagged_argument to match a given 
  // argument with a list of unnamed specs.
  //
  // ParameterSpec is an unnamed spec.
  // Tail is either another unnamed_list specialization,
  // or empty_unnamed_list.
  template <class ParameterSpec, class Tail>
  struct unnamed_list
  {
      // Helper metafunction for apply below. Computes the result
      // of Tail::apply. Returns a pair consisting of:
      //
      //  * the tagged argument
      //  * the unnamed_list that is left after the tagging. Possibly
      //    with one element removed.
      template <class Arg, class Positional, class TagFn>
      struct eval_tail
      {
          typedef typename mpl::apply_wrap3<
              Tail, Arg, Positional, TagFn
          >::type result;

          typedef mpl::pair<
              typename mpl::first<result>::type
            , unnamed_list<ParameterSpec, typename mpl::second<result>::type>
          > type;
      };

      // If this keyword's predicate returns true for
      // the given argument type, tag the argument with
      // ParameterSpec::key_type. Otherwise try the tail.
      template <class Arg, class Positional, class TagFn>
      struct apply
      {
          typedef typename mpl::eval_if<
              typename mpl::apply1<typename ParameterSpec::predicate, Arg>::type
            , mpl::pair<
                  typename mpl::apply_wrap2<
                      TagFn, typename ParameterSpec::key_type, Arg
                  >::type
                , Tail
              >
            ,
#if BOOST_WORKAROUND(__GNUC__, < 3)
              typename unnamed_list<ParameterSpec, Tail>::template
#endif
              eval_tail<Arg, Positional, TagFn>
          >::type type;
      };
  };

  // We need to build a list of all ParameterSpec's that specify an 
  // unnamed argument. This list is used when trying to match an
  // argument to an unnamed keyword.

  template <class ParameterSpec, class TailFn>
  struct make_unnamed_list
  {
      typedef unnamed_list<
          ParameterSpec
        , typename TailFn::type
      > type;
  };

  template <class ParameterSpec, class TailFn>
  struct make_partial_unnamed_list
    : mpl::eval_if<
          is_same<ParameterSpec, void_>
        , mpl::identity<empty_unnamed_list>
        , mpl::eval_if<
              is_unnamed<ParameterSpec>
            , make_unnamed_list<ParameterSpec, TailFn>
            , TailFn
          >
      >
  {};

#define BOOST_PARAMETER_make_unnamed_list(z, n, names)  \
      BOOST_PP_SEQ_ELEM(0,names)<                       \
          BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(1,names), n),
   
#define BOOST_PARAMETER_build_unnamed_list(n, make, parameter_spec)                 \
  BOOST_PP_REPEAT(                                                                  \
      n, BOOST_PARAMETER_make_unnamed_list, (make)(parameter_spec))                 \
  mpl::identity<aux::empty_unnamed_list>                                            \
  BOOST_PP_REPEAT(n, BOOST_PARAMETER_right_angle, _)

  struct tag_keyword_arg
  {
      template <class K, class T>
      struct apply
        : tag<K,T>
      {};
  };

  struct tag_template_keyword_arg
  {
      template <class K, class T>
      struct apply
      {
          typedef template_keyword<K,T> type;
      };
  };

} // namespace aux

#define BOOST_PARAMETER_FORWARD_TYPEDEF(z, i, names) \
    typedef BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0,names),i) BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(1,names),i);

#define BOOST_PARAMETER_FORWARD_TYPEDEFS(n, src, dest) \
    BOOST_PP_REPEAT(n, BOOST_PARAMETER_FORWARD_TYPEDEF, (src)(dest))


#define BOOST_PARAMETER_TEMPLATE_ARGS(z, n, text) class BOOST_PP_CAT(PS, n) = void_

template<
     class PS0
   , BOOST_PP_ENUM_SHIFTED(BOOST_PARAMETER_MAX_ARITY, BOOST_PARAMETER_TEMPLATE_ARGS, _)
>
struct parameters
{
#undef BOOST_PARAMETER_TEMPLATE_ARGS

    typedef typename BOOST_PARAMETER_build_unnamed_list(
        BOOST_PARAMETER_MAX_ARITY, aux::make_partial_unnamed_list, PS
    )::type unnamed_list;

    // if the elements of NamedList match the criteria of overload
    // resolution, returns a type which can be constructed from
    // parameters.  Otherwise, this is not a valid metafunction (no nested
    // ::type).


#ifndef BOOST_NO_SFINAE
    // If NamedList satisfies the PS0, PS1, ..., this is a
    // metafunction returning parameters.  Otherwise it 
    // has no nested ::type.
    template <class NamedList>
    struct match_base
      : mpl::if_<
            // mpl::and_<
            //    aux::satisfies_requirements_of<NamedList,PS0>
            //  , mpl::and_<
            //       aux::satisfies_requirements_of<NamedList,PS1>...
            //           ..., mpl::true_
            // ...> >
            
# define BOOST_PARAMETER_satisfies(z, n, text)                                   \
            mpl::and_<                                                              \
                aux::satisfies_requirements_of<NamedList, BOOST_PP_CAT(PS, n)> ,
      
            BOOST_PP_REPEAT(BOOST_PARAMETER_MAX_ARITY, BOOST_PARAMETER_satisfies, _)
            mpl::true_
            BOOST_PP_REPEAT(BOOST_PARAMETER_MAX_ARITY, BOOST_PARAMETER_right_angle, _)

# undef BOOST_PARAMETER_satisfies

          , mpl::identity<parameters>
          , void_
        >
    {};
#endif
    
    // Specializations are to be used as an optional argument to
    // eliminate overloads via SFINAE
    template<
#if BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564))
        // Borland simply can't handle default arguments in member
        // class templates.  People wishing to write portable code can
        // explicitly specify BOOST_PARAMETER_MAX_ARITY arguments
        BOOST_PP_ENUM_PARAMS(BOOST_PARAMETER_MAX_ARITY, class A)
#else 
        BOOST_PP_ENUM_BINARY_PARAMS(
            BOOST_PARAMETER_MAX_ARITY, class A, = void_ BOOST_PP_INTERCEPT
        )
#endif            
    >
    struct match
# ifndef BOOST_NO_SFINAE
      : match_base<
           typename mpl::apply_wrap1<BOOST_PARAMETER_build_arg_list(
                BOOST_PARAMETER_MAX_ARITY, aux::make_partial_arg_list, PS, A
              , aux::tag_keyword_arg
            ), unnamed_list>::type
        >::type
    {};
# else
    { 
        typedef parameters<
            BOOST_PP_ENUM_PARAMS(BOOST_PARAMETER_MAX_ARITY, PS)
        > type; 
    };
# endif

    // Metafunction that returns an ArgumentPack.
    
    template <
#if BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x564))
        // Borland simply can't handle default arguments in member
        // class templates.  People wishing to write portable code can
        // explicitly specify BOOST_PARAMETER_MAX_ARITY arguments
        BOOST_PP_ENUM_PARAMS(BOOST_PARAMETER_MAX_ARITY, class A)
#else 
        BOOST_PP_ENUM_BINARY_PARAMS(
            BOOST_PARAMETER_MAX_ARITY, class A, = void_ BOOST_PP_INTERCEPT
        )
#endif            
    >
    struct bind
    {
      typedef typename mpl::apply_wrap1<BOOST_PARAMETER_build_arg_list(
            BOOST_PARAMETER_MAX_ARITY, aux::make_partial_arg_list, PS, A
          , aux::tag_template_keyword_arg
        ), unnamed_list>::type type;
    };

    BOOST_PARAMETER_FORWARD_TYPEDEFS(BOOST_PARAMETER_MAX_ARITY, PS, parameter_spec)

    //
    // The function call operator is used to build an arg_list that
    // labels the positional parameters and maintains whatever other
    // tags may have been specified by the caller.
    //
    aux::empty_arg_list operator()() const
    {
       return aux::empty_arg_list();
    }

    template<class A0>
    typename mpl::apply_wrap1<
        aux::make_arg_list<PS0,A0, aux::tag_keyword_arg, mpl::always<aux::empty_arg_list> >
      , unnamed_list      
    >::type
    operator()(A0& a0) const
    {
        typedef typename mpl::apply_wrap1<
            aux::make_arg_list<PS0,A0,aux::tag_keyword_arg,mpl::always<aux::empty_arg_list> >
          , unnamed_list
        >::type result_type;

        return result_type(
            a0
            // , void_(), void_(), void_() ...
            BOOST_PP_ENUM_TRAILING_PARAMS(
                BOOST_PP_SUB(BOOST_PARAMETER_MAX_ARITY, 1)
              , aux::void_reference() BOOST_PP_INTERCEPT)
        );
    }

    template<class A0, class A1>
    typename mpl::apply_wrap1<
        aux::make_arg_list<
            PS0,A0,aux::tag_keyword_arg
          , aux::make_arg_list<
                PS1,A1,aux::tag_keyword_arg
              , mpl::always<aux::empty_arg_list>
            >
        >
      , unnamed_list
    >::type
    operator()(A0& a0, A1& a1) const
    {
        typedef typename mpl::apply_wrap1<
            aux::make_arg_list<
                PS0,A0,aux::tag_keyword_arg
              , aux::make_arg_list<
                    PS1,A1,aux::tag_keyword_arg
                  , mpl::always<aux::empty_arg_list>
                >
            >
          , unnamed_list
        >::type result_type;

        return result_type(
            a0, a1
            // , void_(), void_() ...
            BOOST_PP_ENUM_TRAILING_PARAMS(
                BOOST_PP_SUB(BOOST_PARAMETER_MAX_ARITY, 2)
              , aux::void_reference() BOOST_PP_INTERCEPT)
        );
    }

    // Higher arities are handled by the preprocessor
#define BOOST_PP_ITERATION_PARAMS_1 (3,( \
        3,BOOST_PARAMETER_MAX_ARITY,<boost/parameter/aux_/overloads.hpp> \
    ))
#include BOOST_PP_ITERATE()

};

} // namespace parameter

} // namespace boost

#endif // BOOST_PARAMETERS_031014_HPP
