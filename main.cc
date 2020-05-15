/***************************************************************************
 *
 * Copyright (c) 2019 cubot.cumt, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file main.cc
 **/

#include <iostream>
#include <vector>

#include "convex_hull/convex_hull.h"
#include "line_segments_intersect/line_segments_intersect.h"

void TestLineSegments() {
  struct Point p1 = {1, 1}, q1 = {10, 1};
  struct Point p2 = {1, 2}, q2 = {10, 2};
  LineSegmentsIntersect seg1;
  seg1.Interect(p1, q1, p2, q2) ? std::cout << "Yes\n" : std::cout << "No\n";

  p1 = {10, 0}, q1 = {0, 10};
  p2 = {0, 0}, q2 = {10, 10};
  seg1.Interect(p1, q1, p2, q2) ? std::cout << "Yes\n" : std::cout << "No\n";

  p1 = {-5, -5}, q1 = {0, 0};
  p2 = {1, 1}, q2 = {10, 10};
  seg1.Interect(p1, q1, p2, q2) ? std::cout << "Yes\n" : std::cout << "No\n";
}

void TestConvexHull() {
  std::vector<Point> origin_points;
  Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                    {3, 0}, {0, 0}, {3, 3}};
  for (const auto &point : points) {
    origin_points.emplace_back(point);
  }
  ConvexHull convex_hull;
  std::vector<Point> convex_hull_points;
  std::vector<Point> extrem_points;
  if (!convex_hull.GetConvexHullPoints(origin_points, &convex_hull_points)) {
    return;
  }
  //convex_hull.GetExtremePointsByTrangle(origin_points, &extrem_points);
  convex_hull.GetExtremePointsByEdges(origin_points,&extrem_points);
  for (const auto &point : extrem_points) {
    std::cout << "(" << point.x << "," << point.y << ")" << std::endl;
  }
}

int main() {
  TestLineSegments();
  TestConvexHull();
  return 0;
}
//
//#include <iostream>
//#include <string>
//
// using namespace std;
//
// void DeleteSpace(string &s)
//{
//    int index = 0;
//    if( !s.empty())
//    {
//        while( (index = s.find(' ',index)) != string::npos)
//        {
//            s.erase(index,1);
//        }
//    }
//}
//
// std::string GetURL(std::string str1,std::string str2){
//    if(str1.empty() && str2.empty()){
//        return "/";
//    }
//    if(!str1.empty()){
//        while(reinterpret_cast<const char *>(str1.at(str1.size() - 1)) ==
//        "/"){
//            str1.erase(str1.end()-1);
//        }
//    }
//    if(!str2.empty()){
//        {
//            if (reinterpret_cast<const char *>(str2.at(0)) != "/"){
//                str2 = "/" + str2;
//                cout << "111" <<endl;
//            }
//        }
//    }
//    return str1 + str2;
//}
//
// int nextval[1000001];
// void GetNext(string s){
//    int32_t len=s.length();
//    int32_t j=-1;
//    nextval[0]=-1;
//    for(int32_t i=1;i<len;i++){
//        if(j!=-1&&s[i]!=s[j+1]){
//            j=nextval[j];
//        }
//        if(s[i]==s[j+1])j++;
//        nextval[i]=j;
//    }
//}
//
// int32_t KMP(std::string t,std::string p){
//    GetNext(p);
//    int32_t n=t.length();
//    int32_t m=p.length();
//    int32_t j=-1;
//    int32_t ans=0;
//    for(int32_t i=0;i<n;i++){
//        while(j!=-1&&t[i]!=p[j+1])j=nextval[j];
//        if(t[i]==p[j+1])j++;
//        if(j==m-1){
//            ans++;
//            j=nextval[j];
//        }
//    }
//    return ans;
//}
//
// int32_t CounterSubStr(std::string& str, std::string& sub)
//{
//    int32_t index = 0;
//    while( (index = str.find(' ',index)) != string::npos)
//    {
//        str.erase(index,1);
//    }
//    return KMP(str,sub);
//}
//
// int main(){
//
//    return 0;
//}
