#include <iostream>
#include <tuple>
#include <utility>
#include <math.h>
 
using namespace std;
 
template <typename T>
 
struct Rhombus
{
    using vertex_t = pair<T, T>;
 
public:
    vertex_t points[4];
};
 
template <typename T>
 
struct FiveSquare
{
    using vertex_t = pair<T, T>;
 
public:
    vertex_t points[5];
};
 
template <typename T>
 
class SixSquare
{
 
    using vertex_t = pair<T, T>;
 
public:
    vertex_t points[6];
};
 
template <typename T>
void print(pair<T, T> t)
{
    cout << "(" << t.first << ", " << t.second << ") ";
}
 
template <typename T>
float square(Rhombus<T> r)
{
    float d1 = sqrt(pow(r.points[0].first - r.points[2].first, 2) + pow(r.points[0].second - r.points[2].second, 2));
    float d2 = sqrt(pow(r.points[1].first - r.points[3].first, 2) + pow(r.points[1].second - r.points[3].second, 2));
    return  d1 * d2 / 2;
}
 
template <typename T>
float square(FiveSquare<T> f)
{
    float a = sqrt(pow(f.points[0].first - f.points[1].first, 2) + pow(f.points[0].second - f.points[1].second, 2));
    return pow(a, 2) * sqrt(25.0 + 10.0 * sqrt(5.0)) / 4;
}
 
template <typename T>
float square(SixSquare<T> s)
{
    float a = sqrt(pow(s.points[0].first - s.points[1].first, 2) + pow(s.points[0].second - s.points[1].second, 2));
    return 3 * sqrt(3 * pow(a, 2)) / 2;
}
 
template <typename T>
void print(Rhombus<T> r)
{
    cout << "Rhombus:" << endl;
    for (int i = 0; i < 4; i++)
    {
        print(r.points[i]);
    }
    cout << endl;
}
 
template <typename T>
void print(FiveSquare<T> f)
{
    cout << "Five Square:" << endl;
    for (int i = 0; i < 5; i++)
    {
        print(f.points[i]);
    }
    cout << endl;
}
 
template <typename T>
void print(SixSquare<T> s)
{
    cout << "Five Square:" << endl;
    for (int i = 0; i < 6; i++)
    {
        print(s.points[i]);
    }
    cout << endl;
}
 
template<std::size_t I = 0, typename... T>
inline typename std::enable_if<I == sizeof...(T), void>::type print(std::tuple<T...> t)
{
 
}
 
template<std::size_t I = 0, typename... T>
inline typename std::enable_if < I < sizeof...(T), void>::type  print(std::tuple<T...> t)
{
    print(get<I>(t));
    print<I + 1, T...>(t);
}
 
template<std::size_t I = 0, typename... T>
inline typename std::enable_if<I == sizeof...(T), float>::type square(std::tuple<T...> t, float sum = 0)
{
    return sum;
}
 
template<std::size_t I = 0, typename... T>
inline typename std::enable_if < I < sizeof...(T), float>::type square(std::tuple<T...> t, float sum = 0)
{
    return square<I + 1, T...>(t, sum + square(get<I>(t)));
}
 
int main()
{
    char pointNames[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    Rhombus<float> r;
    FiveSquare<float> f;
    SixSquare<float> s;
    cout << "Input points of rhombus:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << pointNames[i] << ".x = ";
        cin >> r.points[i].first;
        cout << pointNames[i] << ".y = ";
        cin >> r.points[i].second;
    }
    cout << "Input points of five square:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << pointNames[i] << ".x = ";
        cin >> f.points[i].first;
        cout << pointNames[i] << ".y = ";
        cin >> f.points[i].second;
    }
    cout << "Input points of six square:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << pointNames[i] << ".x = ";
        cin >> s.points[i].first;
        cout << pointNames[i] << ".y = ";
        cin >> s.points[i].second;
    }
    tuple<Rhombus<float>, FiveSquare<float>, SixSquare<float>> t(r, f, s);
    print(t);
    cout << "Sum of areas: " << square(t) << endl;
 
    return 0;
}
