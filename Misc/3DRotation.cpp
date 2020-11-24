#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main(){
    double x, y, z, rx, ry, rz, t;
    cin >> x >> y >> z >> rx >> ry >> rz >> t;
    double l = sqrt(rx*rx + ry*ry + rz*rz);
    rx /= l;
    ry /= l;
    rz /= l;
    double d = sqrt(ry*ry + rz*rz);
    double qx, qy, qz;
    if (d != 0) {
        qx = x;
        qy = y * rz / d - z * ry / d;
        qz = y * ry / d + z * rz / d;
    } else {
        qx = x;
        qy = y;
        qz = z;
    }
    x = qx * d - qz * rx;
    y = qy;
    z = qx * rx + qz * d;
    qx = x * cos(t) - y * sin(t);
    qy = x * sin(t) + y * cos(t);
    qz = z;
    x = qx * d + qz * rx;
    y = qy;
    z = -qx * rx + qz * d;
    if (d != 0) {
        qx = x;
        qy = y * rz / d + z * ry / d;
        qz = -y * ry / d + z * rz / d;
    } else {
        qx = x;
        qy = y;
        qz = z;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << qx << " " << qy << " " << qz << endl;
    return 0;
}
