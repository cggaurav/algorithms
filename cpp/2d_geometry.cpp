/* Gaurav Chandrashekar */

#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

/* traversing macros */
#define FOR(i, a, b)       for(int i=int(a); i<=int(b); i++)
#define FORN(i, n)         FOR(i, 1, int(n))
#define RFOR(i, a, b)      for(int i=int(a); i>=int(b); i--)
#define TR(c, it)          for(typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++)

/* shortform macros */
#define PB                 push_back
#define MP                 make_pair
#define SIZE(c)            (int((c).size()))

/* debug and printing macros */
#define _DEBUG(x) cerr<<#x<<" = "<<x<<endl;

/* typedefs */
typedef         long long       LL;
typedef         long double     LD;
typedef         vector<int>     VI;
typedef         vector<bool>    VB;
typedef         pair<int, int>  PII;
typedef         vector< PII >    VPII;
typedef         set<int>        SI;

/* Constants */
#define OO 200000000
#define M_PI 3.14159265358979323846
#define EPSILON 1e-10
#define printPoint(p) cout << "(" << p.x << ", " << p.y << ") "
#define printVector(p) { for (int ii=0; ii<p.size(); ++ii) printPoint(p[ii]); cout << endl; }

/**
    Geometrical library (2D)
    
    equal(double, double);
    isBigger(double, double);
    isSmaller(double, double);
    
    Point();
    Point(double, double);
    int Point.insideSegment();
    double distanceTwoPoints(Point, Point);
    Point rotate(Point,Point,alpha);
    
    Vector();
    Vector(Point, Point);
    double Vector::magnitude();
    double crossProduct(Vector); // ccw
    double dotProduct(Vector);
    double angle(Vector, Vector);
    double angle2(Vector, Vector);
    Vector rotateVector(Vector, alpha);
        
    Line();
    Line(Point, Point);
    Vector Line.normalVector();
    int intersection(Line, Line, Point&);
    int intersectionSegment(Point, Point, Point, Point);
    int sideOfLine(Point, Line);

    double areaTriangle(Point, Point, Point);
    int Point::insideTriangle(Point, Point, Point);    
    
    Polygon();
    void Polygon::add(Point);
    int Polygion::size();
    double Polygon::area();
    Polygon convex_hull(vector<Point>);
*/

////////////////////////////////////////////////////////////////////////
// floating number comparation
////////////////////////////////////////////////////////////////////////

double equal(double a, double b)
{
    return fabs(a-b)<=EPSILON;
}

double isBigger(double a, double b)
{
    return a-EPSILON > b;
}

double isSmaller(double a, double b)
{
    return a+EPSILON < b;
}

////////////////////////////////////////////////////////////////////////
// class Point
////////////////////////////////////////////////////////////////////////
class Point
{
    public:
    double x, y; // int

    Point()
    {
    }

    Point(double x, double y):x(x),y(y) {}

    Point rotate(double alpha)
    {
        Point B;
        B.x = x*cos(alpha) - y*sin(alpha);
        B.y = x*sin(alpha) + y*cos(alpha);
        return B;
    }//actually ze^(i@)=(x+iy)(cos@+isin@)=xcos@-ysin@ + i(xsin@ + ycos@);

    bool insideRectangle(Point A, Point B)
    {
        return !isBigger( (x-A.x)*(x-B.x),0 ) &&
               !isBigger( (y-A.y)*(y-B.y),0 );
    } //   
    
    inline int insideSegment(Point A, Point B);
    
    int insideTriangle(Point A, Point B, Point C);
};
#define sqr(x) ((x)*(x))
inline double distanceTwoPoints(Point A, Point B)
{
    return sqrt ( sqr(A.x-B.x) + sqr(A.y-B.y) );
}
#undef sqr
int Point::insideSegment(Point A, Point B)
{
    double p = distanceTwoPoints(A,*this);
    double q = distanceTwoPoints(B,*this);
    if ( equal(p,0) || equal(q,0) ) return 2; // coincides an endpoint
    else if ( equal(distanceTwoPoints(A,B), p+q) ) return 1;
    return 0;
}

Point midpoint(Point A, Point B)
{
    Point M;
    M.x = (A.x + B.x) / 2;
    M.y = (A.y + B.y) / 2;
    return M;
}

bool equalPoint(Point A, Point B)
{
    return equal(A.x,B.x) && equal(A.y,B.y);
}

////////////////////////////////////////////////////////////////////////
// Vector
////////////////////////////////////////////////////////////////////////
class Vector {
    public:
    double x, y;
    
    Vector() {}
    
    Vector(double x, double y): x(x),y(y) {};
    
    Vector(Point A, Point B) 
    {
        x = B.x - A.x;
        y = B.y - A.y;        
    } 
    
    #define sqr(x) ((x)*(x))
    double magnitude() 
    {
        return sqrt( sqr(x)*sqr(y) );
    }
    #undef sqr
};

inline double dotProduct(Vector a, Vector b)
{
    return a.x*b.x + a.y*b.y;
}

inline double crossProduct(Vector a, Vector b)
{
    return a.x*b.y - a.y*b.x;
}

inline double angle(Vector a, Vector b) // returns angle [0..2*PI] from a to b ( counter clock-wise )
{
    double Angle = atan2(b.y,b.x) - atan2(a.y,a.x);
    if (Angle<0) Angle+=2*M_PI;
    return Angle;
}

double angle2(Vector a, Vector b) // returns angle [0..PI] 
{
    return abs( atan2(b.y,b.x) - atan2(a.y,a.x) );
}

Point rotate(Vector A, double alpha)
{
    Point B;
    B.x = A.x*cos(alpha) - A.y*sin(alpha);
    B.y = A.x*sin(alpha) + A.y*cos(alpha);
    return B;
}

///////////////////////////////////////////////////////////////////////////
// class Line
///////////////////////////////////////////////////////////////////////////
class Line
{
    public:
    double a, b, c; // ax+by+c=0;

    Line()
    {
    }

    Line(Point A, Point B)
    {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -A.x*B.y + A.y*B.x;
    }

    Line(Point O, Vector D)
    {
        a = D.y;
        b = -D.x;
        c = -O.x*D.y + O.y*D.x;
    }
    
    Vector normalVector()
    {
        Vector n;
        n.x = a;
        n.y = b;
        return n;
    }
};

int intersection(Line f, Line g, Point& P)
{
    double a=f.a, b=f.b, c=-f.c;
    double ap=g.a, bp=g.b, cp=-g.c;
    double d=a*bp-b*ap;
    double dx=c*bp-b*cp;
    double dy=a*cp-c*ap;
    if (equal(d,0)) {
        if (equal(dx,0) && equal(dy,0)) return -1; // vo so nghiem
        else return 0; // vo nghiem
    }
    else {
        P.x = dx/d;
        P.y = dy/d;
        return 1; // co nghiem
    }
}

int intersectionSegment(Point A, Point B, Point C, Point D) // [AB] intersect [CD] ?
{
    Point P;
    return intersection(Line(A,B), Line(C,D), P)==1 &&
           P.insideRectangle(A,B) &&
           P.insideRectangle(C,D);
}

int intersectionSegment2(Point A, Point B, Point C, Point D) // (AB) intersect (CD) ?
{
    Point P;
    
    if (intersection(Line(A,B), Line(C,D), P) == -1) {
        if ( A.insideSegment(C,D)==1 ||
             B.insideSegment(C,D)==1 ||
             C.insideSegment(A,B)==1 ||
             D.insideSegment(A,B)==1 ) return 1; // inter
        else return 0; // no
    }
    
    return intersection(Line(A,B), Line(C,D), P)==1 &&
           P.insideSegment(A,B)==1 &&
           P.insideSegment(C,D)==1;
}

int sideOfLine(Point p, Line f) 
{
    double h = f.a*p.x + f.b*p.y + f.c;
    if ( equal(h,0) ) return 0;
    else if (h>0) return 1;
    else return -1;
}

double distanceToLine(Point p, Line f)
{
    return fabs(f.a * p.x + f.b * p.y + f.c) / sqrt(f.a*f.a + f.b*f.b);
}
////////////////////////////////////////////////////////////////////////
// Triangle
////////////////////////////////////////////////////////////////////////
double areaTriangle(Point A, Point B, Point C)
{
    return fabs(crossProduct(Vector(A,B),Vector(A,C))) / 2;
}

int Point::insideTriangle(Point A, Point B, Point C)
{
    double p = areaTriangle(A,B,*this);
    double q = areaTriangle(B,C,*this);
    double r = areaTriangle(C,A,*this);
    if ( equal(p,0) || equal(q,0) || equal(r,0) ) return 2; // insides a side
    else if ( areaTriangle(A,B,C), p+q+r ) {
    }
}

////////////////////////////////////////////////////////////////////////
// Polygon
////////////////////////////////////////////////////////////////////////
class Polygon
{
    public:
    vector<Point> vertex;
    
    Polygon() { }
    
    Point& operator[] (int i)
    {
        return vertex[i];
    }        
    
    void add(Point p)
    {
        vertex.push_back(p);
    }
    
    void pop()
    {
        vertex.erase( vertex.end()-1 );
    }
    
    int size()
    {
        return vertex.size();
    }
    
    #define determiner(a,b,c,d) ((a)*(d)-(b)*(c))
    double area() {
        int n = vertex.size();
        double s = 0;
        for (int i=0; i<n; ++i) {
            int j = (i+1)%n;
            s += (vertex[i].y + vertex[j].y) * (vertex[i].x - vertex[j].x);
        }
        return fabs(s)/2;        
    }    
    #undef determiner
    
    double circumference() 
    {
        int n = vertex.size();
        double s = 0;
        for (int i=0; i<n; ++i) {
            int j = (i+1)%n;
            s += distanceTwoPoints( vertex[i], vertex[j] );
        }
        return s;
    }    
};

class compareTg {
    Point O;    
    public:
        bool operator () (Point A, Point B) 
        {
            double c = crossProduct( Vector(O,A), Vector(O,B) );
            if ( equal(c,0) ) {
                return ( distanceTwoPoints(O,A) > distanceTwoPoints(O,B) );
            }
            else if (c < 0) return false;
            else return true; // re trai
        }
        
        compareTg(Point O):O(O) {}
};


// Warning: this functions maybe fails if there are two roots
Polygon convex_hull(vector<Point> v) // can be &v
{ 
    /** find xmin */
    int root=0;
    for (int i=0; i<v.size(); ++i) 
        if ( (v[i].x < v[root].x) || (v[i].x == v[root].x && v[i].y < v[root].y) ) root=i;            
    
    /** sort */
    swap( v[0], v[root] );
    sort( v.begin()+1, v.end(), compareTg(v[0]) );    
    
    /** scan */
    v.push_back( v[0] ); 
    
    Polygon hull;
    hull.add( v[0] );
    hull.add( v[1] );    
    
    for (int i=2; i < v.size(); ++i) 
    {
        while (hull.size() >= 2) 
        {
            int n = hull.size();
            double cp = crossProduct( Vector(hull[n-2], hull[n-1]),    Vector(hull[n-1], v[i]) );
            if ( cp<0 ) hull.pop();
            else {
                if ( !v[i].insideSegment(v[0],hull[n-1]) ) hull.add( v[i] );
                break;
            }
        }
    }
    
    v.erase(v.end()-1);
            
    return hull;
}    

int insidePolygon(Point A, Polygon P)
{
    Point B( A.x + 1234567, A.y + 1234568 );
    
    int cnt=0;
    for (int i=0; i<P.size(); ++i) {
        int j=(i+1)%P.size();
        if ( A.insideSegment(P[i],P[j]) ) return 2; // boundary
        else if ( intersectionSegment(A,B,P[i],P[j]) ) ++cnt;
    }        
    
    if (cnt%2) return 1; // inside
    return 0; // outside
}

////////////////////////////////////////////////////////////////////////
// Circle
////////////////////////////////////////////////////////////////////////
class Circle {
    public:
    Point center;
    double radius;
    
    Circle ();
    Circle (Point O, double radius) : center(O), radius(radius) {};
        
    Circle (Point A, Point B, Point C)
    {                
        if ( equalPoint(A,B) || equalPoint(B,C) ) {
            center = midpoint(A,C);
            radius = distanceTwoPoints(A,C)/2;
        }
        else if ( equalPoint(A,C) ) {
            center = midpoint(A,B);
            radius = distanceTwoPoints(A,B)/2;
        }
        else {
            Vector AB (A,B);
            Line tt1 ( midpoint(A,B), Vector(-AB.y, AB.x) );
            Vector AC (A,C);
            Line tt2 ( midpoint(A,C), Vector(-AC.y, AC.x) );
            intersection(tt1, tt2, center);                        
            radius = distanceTwoPoints(center, A);            
        }
    }
};

int insideCircle(Point P, Circle C)
{
    double d = distanceTwoPoints(P, C.center);
    if (equal(d,C.radius)) return 2;
    else if (d<C.radius) return 1;
    else return 0;
}


#define SQR(x) ((x)*(x))
void tangent(Point P, Circle C, Line& f, Line& g)
{
    double d = distanceTwoPoints(P, C.center);
    double l = sqrt ( SQR(d) - SQR(C.radius) );
    double cos_alpha = l/d;
    double sin_alpha = C.radius/d;
    
    Vector D (P, C.center);
    
    Vector T;    
    T.x = D.x*cos_alpha - D.y*sin_alpha;
    T.y = D.x*sin_alpha + D.y*cos_alpha;
    g = Line( P,T );

    T.x = D.x*cos_alpha - D.y*(-sin_alpha);
    T.y = D.x*(-sin_alpha) + D.y*cos_alpha;
    f = Line( P,T );
}
#undef SQR
int main()
{
    return 0;
}
