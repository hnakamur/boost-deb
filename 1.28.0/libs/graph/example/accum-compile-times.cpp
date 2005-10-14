//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee, 
//
// This file is part of the Boost Graph Library
//
// You should have received a copy of the License Agreement for the
// Boost Graph Library along with the software; see the file LICENSE.
// If not, contact Office of Research, Indiana University,
// Bloomington, IN 47405.
//
// Permission to modify the code and to distribute the code is
// granted, provided the text of this NOTICE is retained, a notice if
// the code was modified is included with the above COPYRIGHT NOTICE
// and with the COPYRIGHT NOTICE in the LICENSE file, and that the
// LICENSE file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//=======================================================================
#include <boost/config.hpp>
#include <fstream>
#include <iostream>
#include <numeric>
#include <iterator>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/property_iter_range.hpp>

namespace std
{
  template < typename T >
  std::istream& operator >> (std::istream& in, std::pair < T, T > &p)
  {
    in >> p.first >> p.second;
    return in;
  }
}

namespace boost
{
  enum vertex_compile_cost_t { vertex_compile_cost };
  BOOST_INSTALL_PROPERTY(vertex, compile_cost);
}

using namespace boost;

typedef adjacency_list< listS, // Store out-edges of each vertex in a std::list
  listS,                       // Store vertex set in a std::list
  directedS,                   // The file dependency graph is directed
  // vertex properties
  property < vertex_name_t, std::string,
  property < vertex_compile_cost_t, float,
  property < vertex_distance_t, float,
  property < vertex_color_t, default_color_type > > > >,
  // an edge property
  property < edge_weight_t, float > >
  file_dep_graph2;

typedef graph_traits<file_dep_graph2>::vertex_descriptor vertex_t;
typedef graph_traits<file_dep_graph2>::edge_descriptor edge_t;

int
main()
{
  std::ifstream file_in("makefile-dependencies.dat");
  typedef graph_traits<file_dep_graph2>::vertices_size_type size_type;
  size_type n_vertices;
  file_in >> n_vertices;        // read in number of vertices
#ifdef BOOST_MSVC
  // std::istream_iterator causes trouble with VC++
  std::vector<vertex_t> id2vertex;
  file_dep_graph2 g;
  for (std::size_t i = 0; i < n_vertices; ++i)
    id2vertex.push_back(add_vertex(g));
  std::pair<size_type, size_type> p;
  while (file_in >> p) 
    add_edge(id2vertex[p.first], id2vertex[p.second], g);
#else
  std::istream_iterator<std::pair<size_type, size_type> >
    input_begin(file_in), input_end;
  file_dep_graph2 g(input_begin, input_end, n_vertices);
#endif

  typedef property_map < file_dep_graph2, vertex_name_t >::type name_map_t;
  typedef property_map < file_dep_graph2, vertex_compile_cost_t >::type
    compile_cost_map_t;
  typedef property_map <file_dep_graph2, vertex_distance_t >::type
    distance_map_t;
  typedef property_map <file_dep_graph2, vertex_color_t >::type 
    color_map_t;

  name_map_t name_map = get(vertex_name, g);
  compile_cost_map_t compile_cost_map = get(vertex_compile_cost, g);
  distance_map_t distance_map = get(vertex_distance, g);
  color_map_t color_map = get(vertex_color, g);

  std::ifstream name_in("makefile-target-names.dat");
  std::ifstream compile_cost_in("target-compile-costs.dat");
  graph_traits < file_dep_graph2 >::vertex_iterator vi, vi_end;
  for (tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
    name_in >> name_map[*vi];
    compile_cost_in >> compile_cost_map[*vi];
  }

  graph_property_iter_range < file_dep_graph2,
    vertex_compile_cost_t >::iterator ci, ci_end;
  tie(ci, ci_end) = get_property_iter_range(g, vertex_compile_cost);
  std::cout << "total (sequential) compile time: "
    << std::accumulate(ci, ci_end, 0.0) << std::endl;

  return 0;
}

