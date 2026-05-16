#include <iostream>

struct AdData
{
    int adsWatched{0};
    double percentageClicked{0};
    int avgEarnings{0};
};

void printData(AdData &data)
{
    double total {static_cast<double>(data.adsWatched) * data.percentageClicked * static_cast<double>(data.avgEarnings)};
    std::cout << "Ads watched: " << data.adsWatched << " Percentage clicked: " << data.percentageClicked * 100 << "%" << " Average Earnings: " << data.avgEarnings << " Total earnings: $" << total << '\n';
}

int main()
{
    AdData ad1 {5, 0.8, 300};
    AdData ad2 {9, 0.4, 102};

    printData(ad1);
    printData(ad2);

    return 0;
}