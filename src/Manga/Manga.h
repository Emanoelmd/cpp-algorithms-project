#pragma once

class Manga {
    private:
        char titulo[100];
        char autor[50];
        char genero[50];
        int volumes;
        float minhaNota;
    public:
        Manga(const char* titulo_p, const char* autor_p, const char* genero_p, int volume_p, float minhaNota_p);

        void imprimirDetalhes();
};