/***************************************************************************
 *
 * Copyright (c) 2019 cubot.cumt, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file convex_hull.h
 **/
#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

#include "point.h"

class ConvexHull {
public:
  ConvexHull();
  ~ConvexHull() = default;
  bool GetConvexHullPoints(const std::vector<Point> &origin_points,
                           std::vector<Point> *const convex_hull) const;

  bool GetExtremePointsByTrangle(const std::vector<Point> &origin_points,
                                 std::vector<Point> *const extrem_points) const;
  bool GetExtremePointsByEdges(const std::vector<Point> &origin_points,
                               std::vector<Point> *const extrem_points) const;

private:
  int Orientation(const Point &p, const Point &q, const Point &r) const;
  double Area2(const Point &start_point, const Point &end_point,
               const Point &test_point) const;
  bool ToLeft(const Point &start_point, const Point &end_point,
              const Point &test_point) const;
  bool IsTrangle(const Point &p, const Point &q, const Point &r,
                 const Point &s) const;
  bool CheckEdge(std::vector<Point>& points,const int32_t p, const int32_t q) const;
};
