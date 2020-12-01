#include <gtest/gtest.h>

#include <graph.h>

namespace UT
{

TEST(TestGraph, EmptyGraphUnit)
{
    Graph g;

    EXPECT_EQ(g.get_num_vertices(), 0u);
}

TEST(TestGraph, AddSameEdgeUnit)
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(1, 0);

    EXPECT_EQ(g.get_num_vertices(), 2u);
    EXPECT_TRUE(g.has_edge(0, 1));
    EXPECT_TRUE(g.has_edge(1, 0));
}

TEST(TestGraph, AddEdgesUnit)
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(3, 4);

    EXPECT_EQ(g.get_num_vertices(), 5u);
    EXPECT_TRUE(g.has_edge(0, 1));
    EXPECT_TRUE(g.has_edge(0, 2));
    EXPECT_TRUE(g.has_edge(0, 3));
    EXPECT_TRUE(g.has_edge(1, 2));
    EXPECT_TRUE(g.has_edge(3, 4));
    EXPECT_FALSE(g.has_edge(0, 4));
}

TEST(TestGraph, ColoringListUnit)
{
    const size_t num_edges = 10;
    Graph g;
    for (size_t i = 0; i < num_edges; ++i)
    {
        g.add_edge(i, i + 1);
    }
    EXPECT_EQ(g.get_num_vertices(), 11u);
    EXPECT_EQ(g.brute_force_chromatic_number(), 2u);
    EXPECT_EQ(g.lawler_chromatic_number(), 2u);
}

TEST(TestGraph, ColoringTrianglesUnit)
{
    const size_t num_edges = 5;
    Graph g;
    for (size_t i = 0; i < num_edges; ++i)
    {
        g.add_edge(i, i + 1);
        g.add_edge(i, i + 2);
    }
    EXPECT_EQ(g.get_num_vertices(), 7u);
    EXPECT_EQ(g.brute_force_chromatic_number(), 3u);
    EXPECT_EQ(g.lawler_chromatic_number(), 3u);
}

TEST(TestGraph, ColoringCommonCenterUnit)
{
    const size_t num_edges = 7;
    Graph g;
    for (size_t i = 1; i < num_edges; ++i)
    {
        g.add_edge(i, i + 1);
        g.add_edge(i, 0);
    }
    // Closure
    g.add_edge(0, 7);
    g.add_edge(1, 7);

    EXPECT_EQ(g.get_num_vertices(), 8u);
    EXPECT_EQ(g.brute_force_chromatic_number(), 4u);
    EXPECT_EQ(g.lawler_chromatic_number(), 4u);
}

TEST(TestGraph, ColoringAllIntertwinedUnit)
{
    const size_t num_edges = 6;
    Graph g;
    for (size_t i = 0; i < num_edges; ++i)
    {
        for (size_t j = i + 1; j < num_edges; ++j)
        {
            g.add_edge(i, j);
        }
    }
    EXPECT_EQ(g.get_num_vertices(), 6u);
    EXPECT_EQ(g.brute_force_chromatic_number(), num_edges);
    EXPECT_EQ(g.lawler_chromatic_number(), num_edges);
}

}