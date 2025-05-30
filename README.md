# Sorting Benchmark

Projekt realizowany w ramach przedmiotu **Algorytmy i Złożoność Obliczeniowa**.

Autor: **Gabriel Malanowski**
Prowadzący: **mgr inż. Damian Mroziński**
Data: **27.04.2025**

---

## Opis projektu

Celem projektu jest implementacja i analiza efektywności różnych algorytmów sortowania bez użycia gotowych struktur danych (`std::vector`, `std::list`, itp.).
Projekt obejmuje także przygotowanie własnych struktur danych, pomiar wydajności oraz automatyzację testów.

Zaimplementowane algorytmy sortowania:
- Heap Sort
- Insertion Sort
- Drunk Insertion Sort (wariant z losową zamianą elementów)
- Quick Sort
- Shell Sort

Typy danych obsługiwane w badaniach:
- `int`
- `float`
- `double`
- `char`
- `BoardGame` (własny typ reprezentujący grę planszową)

---

## Budowanie projektu

Wymagania:
- Kompilator C++ z obsługą standardu C++17 (np. GCC 9+)
- CMake 3.10 lub nowszy

Kroki budowania:

```bash
git clone https://github.com/gmalanowski/Sorting-Benchmark.git
cd Sorting-Benchmark-main
mkdir build
cd build
cmake ../CMakeLists.txt
make
```

Uruchamianie badań:

```bash
./studies/runStudies.sh
```

