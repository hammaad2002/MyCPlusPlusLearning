#include <cmath>
#include <matplot/matplot.h>
// using namespace matplot;

int main() {
    std::vector<double> x = matplot::linspace(0, 2 * matplot::pi);
    std::vector<double> y = matplot::transform(x, [](auto x) { return sin(x); });

    matplot::plot(x, y, "-o");
    matplot::show();
    return 0;
}


