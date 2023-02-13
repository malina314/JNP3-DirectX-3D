# Labirynt

Projekt zaliczeniowy DirectX 3D z przedmiotu JNP3.

## Uruchomienie

Projekt posiada standardowy plik CMake. Po zbudowaniu projektu należy zadbać,
aby powstały plik wykonywalny `labyrinth.exe` uruchamiać w tym samym
folderze, w którym znajduje się folder `assets`. Można to osiągnąć, na przykład
poprzez odpowiednie ustawienie "working directory" w swoim IDE, albo
poprzez skopiowanie folderu `assets` do folderu z plikiem wykonywalnym, lub na
odwrót.

## Sterowanie

Sterowanie odbywa się za pomocą klawiatury.
- WSAD - poruszanie się
- strzałki - obrót kamery

`W` powoduje ruch do przodu w kierunku, w którym patrzy kamera. W szczególności
oznacza to, że patrząc się w górę, `W` powoduje ruch w górę.

## Opis projektu

Projekt przedstawia labirynt, z którego należy wydostać. Mapa labiryntu, która
może okazać się bardzo pomocna, znajduje się
[tutaj](https://github.com/malina314/JNP3-DirectX-3D/blob/master/assets/labirynth.png).
Gra nie posiada systemu kolizji, dlatego uprasza się o nieoszukiwanie :)
