/***************************************************************************
 *
 * Copyright (c) 2019 cubot.cumt, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file convex_hull.cc
 **/
#include "convex_hull/convex_hull.h"

#include <cmath>

constexpr double kMathEpsilon = 1e-6;

ConvexHull::ConvexHull() {}

bool ConvexHull::GetConvexHullPoints(
    const std::vector<Point> &origin_points,
    std::vector<Point> *const convex_hull) const {
  if (origin_points.size() < 3) {
    return false;
  }
  int l = 0;
  int n = origin_points.size();
  //找到坐标x最小的点
  for (int i = 1; i < n; ++i) {
    if (origin_points[i].x < origin_points[l].x) {
      l = i;
    }
  }
  int p = l;
  int q;
  do {
    convex_hull->emplace_back(origin_points[p]);
    q = (p + 1) % n;
    for (int i = 0; i < n; i++) {
      // If i is more counterclockwise than current q, then
      // update q
      if (Orientation(origin_points[p], origin_points[q], origin_points[i]) ==
          2) {
        q = i;
      } //逆时针时更新
    }
    p = q;
  } while (p != l);
  return true;
}

bool ConvexHull::GetExtremePointsByTrangle(
    const std::vector<Point> &origin_points,
    std::vector<Point> *const extrem_points) const {
  std::vector<Point> points;
  points.assign(origin_points.begin(), origin_points.end());
  for (uint32_t i = 0; i < origin_points.size(); ++i) {
    points[i].extrem = true;
  }
  for (int32_t p = 0; p < origin_points.size(); p++) {
    for (int32_t q = 0; q < origin_points.size(); q++) {
      for (int32_t r = 0; r < origin_points.size(); r++) {
        for (int32_t s = 0; s < origin_points.size(); s++) {
          if (s == p || s == q || s == r || !points.at(s).extrem) {
            continue;
          }
          if (IsTrangle(points.at(p), points.at(q), points.at(r),
                        points.at(s))) {
            points[s].extrem = false;
          }
        }
      }
    }
  }

  for (const auto &point : points) {
    if (point.extrem) {
      extrem_points->emplace_back(point);
    }
  }
  return true;
}

bool ConvexHull::GetExtremePointsByEdges(
    const std::vector<Point> &origin_points,
    std::vector<Point> *const extrem_points) const {
  std::vector<Point> points;
  points.assign(origin_points.begin(), origin_points.end());
  for (int32_t i = 0; i < points.size(); ++i) {
    points[i].extrem = false;
  }
  for (int32_t p = 0; p < points.size(); ++p) {
    for (int32_t q = p + 1; q < points.size(); ++q) {
      CheckEdge(points, p, q);
    }
  }
  for (const auto &point : points) {
    if (point.extrem) {
      extrem_points->emplace_back(point);
    }
  }
  return true;
}

int ConvexHull::Orientation(const Point &p, const Point &q,
                            const Point &r) const {
  double res = (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x);
  if (res == 0) {
    return res;
  }
  return res > 0 ? 1 : 2;
}

double ConvexHull::Area2(const Point &start_point, const Point &end_point,
                         const Point &test_point) const {
  return start_point.x * end_point.y - start_point.y * end_point.x +
         end_point.x * test_point.y - end_point.y * test_point.x +
         test_point.x * start_point.y - test_point.y * start_point.x;
}

bool ConvexHull::ToLeft(const Point &start_point, const Point &end_point,
                        const Point &test_point) const {
  return (Area2(start_point, end_point, test_point) > 0 + kMathEpsilon);
}

bool ConvexHull::IsTrangle(const Point &p, const Point &q, const Point &r,
                           const Point &s) const {
  auto qpLeft = ToLeft(p, q, s);
  auto qrLeft = ToLeft(q, r, s);
  auto rqLeft = ToLeft(r, p, s);
  return (qpLeft && qrLeft && rqLeft);
}

bool ConvexHull::CheckEdge(std::vector<Point> &points, const int32_t p,
                           const int32_t q) const {
  bool lEmpty = true, rEmpty = true;
  for (int32_t i = 0; i < points.size() && (lEmpty || rEmpty); ++i) {
    if (i != p && i != q) {
      ToLeft(points[p], points[q], points[i]) ? lEmpty = false : rEmpty = false;
    }
  }
  if (lEmpty || rEmpty) {
    points[p].extrem = true;
    points[q].extrem = true;
  }
  return true;
}
