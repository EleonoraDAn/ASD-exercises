#ifndef CATENAMONTAGGIO_HPP
#define CATENAMONTAGGIO_HPP

#include <iostream>
#include <vector>
/* TO-DO: DA RIVEDERE */
class CatenaMontaggio {
    private:
        std::vector<int> tempi_elaborazione;
        std::vector<int> tempi_trasferimento;
        int tempo_avvio;
        int tempo_fermo;
    public:
        CatenaMontaggio(std::vector<int> elab, std::vector<int> trasf, int tA, int tF) {
            tempi_elaborazione = elab;
            tempi_trasferimento = trasf;
            tempo_avvio = tA;
            tempo_fermo = tF;
        }

        int percorsoPiuVeloce(int e1, int e2, int x1, int x2, std::vector<int>& L) {
            int n = tempi_elaborazione.size();
            std::vector<int> f1(n), f2(n);
            f1[0] = tempo_avvio + tempi_elaborazione[0];
            f2[0] = tempo_avvio + tempi_elaborazione[1] + tempi_trasferimento[0];

            for(int j = 1; j < n; j++) {
                if(f1[j-1] + tempi_elaborazione[j] + e1 <= f2[j-1] + tempi_trasferimento[j-1] + tempi_elaborazione[j] + e2) {
                    f1[j] = f1[j-1] + tempi_elaborazione[j];
                    L[j] = 1;
                } else { 
                    f1[j] = f2[j-1] + tempi_trasferimento[j-1] + tempi_elaborazione[j];
                    L[j] = 2;
                }
                if(f2[j-1] + tempi_elaborazione[j] + e2 <= f1[j-1] + tempi_trasferimento[j-1] + tempi_elaborazione[j+1] + e1) {
                    f2[j] = f2[j-1] + tempi_elaborazione[j];
                    L[j] = 2;
                } else { 
                    f2[j] = f1[j-1] + tempi_trasferimento[j-1] + tempi_elaborazione[j+1];
                    L[j] = 1;
                }
            }
            int fStar = std::min(f1[n-1]+x1, f2[n-1]+x2);
            return fStar;
        }
};
#endif