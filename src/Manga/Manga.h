#pragma once

class Manga {
    private:
        char titulo[100];
        char autor[50];
        char genero[50];
        int volumes;
        float nota;
    public:
        Manga(const char* titulo_p, const char* autor_p, const char* genero_p, int volume_p, float nota_p);

        void imprimirDetalhes();

        const char* getTitulo() const;
        const char* getAutor() const;
        const char* getGenero() const;
        int getVolumes() const;
        float getNota() const;

        void setTitulo(const char* novoTitulo);
        void setAutor(const char* novoAutor);
        void setGenero(const char* novoGenero);
        void setVolumes(int novosVolumes);
        void setNota(float novaNota);
};