/***************************************************************************
 *
 * Copyright (c) 2019 cubot.cumt, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file line_segments_intersect.cc
 **/
#include "line_segments_intersect/line_segments_intersect.h"

#include <iostream>
LineSegmentsIntersect::LineSegmentsIntersect() {}
bool LineSegmentsIntersect::Interect(const Point &p1, const Point &q1,
                                     const Point &p2, const Point &q2) const {
    int o1 = Orientation(p1,q1,p2);
    int o2 = Orientation(p1,q1,q2);
    int o3 = Orientation(p2,q2,p1);
    int o4 = Orientation(p2,q2,q1);
    //不共线时
    if(o1 != o2 && o3 != o4){
        return true;
    }
    //存在三个点共线时
    if(o1 == 0 && OnSegment(p1,q1,p2)){
        return true;
    }
    if(o2 == 0 && OnSegment(p1,q1,p2)){
        return true;
    }
    if(o3 == 0 && OnSegment(p2,q2,p1)){
        return true;
    }
    if(o4 == 0 && OnSegment(p2,q2,q1)){
        return true;
    }
    return false;
}
//判断点r是否在pq线段上
bool LineSegmentsIntersect::OnSegment(const Point &p, const Point &q,
                                      const Point &r) const {
  return r.x <= std::max(p.x, q.x) && r.x >= std::min(p.x, q.x) &&
         r.y <= std::max(p.y, q.y) && r.y >= std::min(p.y, q.y);
}
//判断pqr三点的方向，1代表顺时针，2代表逆时针，0代表共线
//采用向量叉乘的方法，根据右手法则，ax*by-bx*ay>0则为顺时针
int LineSegmentsIntersect::Orientation(const Point &p, const Point &q,
                                       const Point &r) const {
  double res = (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x);
  if (res == 0) {
    return res;
  }
  return res > 0 ? 1: 2;
}
