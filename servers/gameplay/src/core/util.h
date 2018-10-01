//
// Created by moreal-gram on 2018-10-01.
//

#ifndef PROJECT_UTIL_H
#define PROJECT_UTIL_H


namespace Util {
    class Vector2 {
        double x;
        double y;

     public:
        Vector2 (double x, double y) : x(x), y(y) {

        }

        inline double GetX() const { return x; }
        inline double GetY() const { return y; }
        inline double GetDistance(Vector2& vector2) const {
            return (vector2.x - x) * (vector2.y - y);
        }

        inline void operator +(Vector2 vector2) {
            x += vector2.x;
            y += vector2.y;
        }

        inline void operator -(Vector2 vector2) {
            x -= vector2.x;
            y -= vector2.y;
        }

        inline void operator *(const double literal) {
            x *= literal;
            y *= literal;
        }

        inline void operator /(const double literal) {
            x /= literal;
            y /= literal;
        }

        inline bool operator ==(Vector2 vector2) {
            return x == vector2.x && y == vector2.y;
        }

        inline void operator +=(Vector2 vector2) {
            x += vector2.x;
            y += vector2.y;
        }

        inline void operator -=(Vector2 vector2) {
            x -= vector2.x;
            y -= vector2.y;
        }

        inline void operator /=(const double literal) {
            x /= literal;
            y /= literal;
        }

        inline void operator *=(const double literal) {
            x *= literal;
            y *= literal;
        }
    };
};


#endif //PROJECT_UTIL_H
