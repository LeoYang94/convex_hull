/***************************************************************************
 *
 * Copyright (c) 2019 cubot.cumt, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file line_segments_intersect.h
 **/
#pragma once
#include "common/point.h"
class LineSegmentsIntersect {
public:
  LineSegmentsIntersect();
  ~LineSegmentsIntersect() = default;
  bool Interect(const Point &p1, const Point &q1, const Point &p2,
                const Point &q2) const;

private:
  bool OnSegment(const Point &p, const Point &q, const Point &r) const;
  int Orientation(const Point &p, const Point &q, const Point &r) const;
};