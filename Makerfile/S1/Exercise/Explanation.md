# Makefile Forklaringer

### Compiler og Værktøjer
```makefile
CXX := g++
AR := ar
RM := rm -f
```
- Bruger g++ som C++ compiler
- ar til at lave statiske biblioteker
- rm til at fjerne filer under oprydning

### Compiler Flag
```makefile
CXXFLAGS := -std=c++17 -Wall -Wextra -I$(INC_DIR)
```
- C++17 standard for moderne C++ features
- Wall og Wextra for udførlige advarsler
- Include-sti til headerfiles

### Debug/Release Build
```makefile
ifeq ($(BUILD_TYPE), debug)
    CXXFLAGS += -Og -g
else ifeq ($(BUILD_TYPE), release)
    CXXFLAGS += -O2 -DNDEBUG
```
- Debug build med -Og for bedre debugging
- Release build med -O2 for optimering
- NDEBUG deaktiverer assertions i release

### Dependency Tracking
```makefile
DEPFLAGS := -MMD -MP
```
- Automatisk generering af header-afhængigheder
- Sikrer at filer rekompileres når headers ændres

### Targets
- `all`: Bygger app, tests og bibliotek
- `run`: Kører programmet med test-input
- `test`: Kører unit tests
- `clean`: Fjerner build-mappen
- `debug/release`: Specificerer build type

### Statisk Bibliotek
- Samler algoritme-implementeringer i `libclassics.a`
- Genbruges af både hovedprogrammet og tests

## Begrundelse for Valg
1. **Separate Objektfiler**: Gør det muligt kun at rekompilere ændrede filer
2. **Statisk Bibliotek**: Samler algoritmerne ét sted og gør linking nemmere
3. **Automatiske Dependencies**: Sikrer korrekt rebuilding ved header-ændringer
4. **Debug/Release Builds**: Forskellige optimeringslevels til udvikling/produktion
5. **Stille Output**: Bruger @ for at gøre output mere læsevenligt
6. **Hjælpe-targets**: Gør det nemt at bygge, teste og rydde op

## Brug af Makefilen
```bash
make        # Standard (debug) build
make run    # Kør programmet
make test   # Kør tests
make release # Lav optimeret version
make clean  # Ryd op
```