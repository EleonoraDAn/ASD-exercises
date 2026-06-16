#ifndef CATENAMONTAGGIO_HPP
#define CATENAMONTAGGIO_HPP

#include <iostream>
#include <vector>
/* TO-DO: DA RIVEDERE */
class CatenaMontaggio {
    private:
        std::vector<std::vector<int>> a;
        std::vector<std::vector<int>> t;
        int e1, e2, x1, x2;
    public:
        CatenaMontaggio(std::vector<std::vector<int>> avvio, std::vector<std::vector<int>> trasferimento, int entry1, int entry2, int exit1, int exit2) {
            a = avvio;
            t = trasferimento;
            e1 = entry1;
            e2 = entry2;
            x1 = exit1;
            x2 = exit2;

        }

        int percorsoPiuVeloce(std::vector<std::vector<int>>& L) {
            int n = a[0].size();
            std::vector<int> f1(n), f2(n);
            f1[0] = a[0][0] + e1;
            f2[0] = a[1][0] + e2;

            for(int j = 1; j < n; j++) {
                if(f1[j-1] + a[0][j] <= f2[j-1] + t[1][j-1] + a[0][j]) {
                    f1[j] = f1[j-1] + a[0][j];
                    L[0][j] = 1;
                } else { 
                    f1[j] = f2[j-1] + t[1][j-1] + a[0][j];
                    L[0][j] = 2;
                }
                if(f2[j-1] + a[1][j] <= f1[j-1] + t[0][j-1] + a[1][j]) {
                    f2[j] = f2[j-1] + a[1][j];
                    L[1][j] = 2;
                } else { 
                    f2[j] = f1[j-1] + t[0][j-1] + a[1][j];
                    L[1][j] = 1;
                }
            }
            int fStar;
            if(f1[n-1] + x1 <= f2[n-1] + x2) {
                fStar = f1[n-1] + x1;
                L[0][0] = 1;
            } else {
                fStar = f2[n-1] + x2;
                L[0][0] = 2;
            }

            return fStar;
        }
};
#endif