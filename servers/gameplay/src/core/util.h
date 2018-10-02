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
        inline double GetDistance(Vector2& other) const {
            return (other.x - x) * (other.y - y);
        }

        inline Vector2 operator +(const Vector2 other) {
            return Vector2 { x + other.x, y + other.y };
        }

        inline Vector2 operator -(const Vector2 other) {
            return Vector2 { x - other.x, y - other.y };
        }

        inline Vector2 operator *(const double literal) {
            return Vector2 { x * literal, y * literal };
        }

        inline Vector2 operator /(const double literal) {
            return Vector2 { x / literal, y / literal };
        }

        inline bool operator ==(Vector2 other) {
            return x == other.x && y == other.y;
        }

        inline Vector2& operator +=(Vector2 other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        inline Vector2& operator -=(Vector2 other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        inline Vector2& operator /=(const double literal) {
            x /= literal;
            y /= literal;
            return *this;
        }

        inline Vector2& operator *=(const double literal) {
            x *= literal;
            y *= literal;
            return *this;
        }
    };
};


#endif //PROJECT_UTIL_H
