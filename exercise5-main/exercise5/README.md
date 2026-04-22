# Hausübung 5 (2 Punkte)

**Ausgabe**: Dienstag 21. April, vormittags.

**Abgabe bis**: Montag 4. Mai, Ende des Tages.

**Abgabe via**: git-Repository mit dem Namen **`exercise5`** auf unserem git-Server https://sgit.iue.tuwien.ac.at

Wichtig: Sie benötigen ein `recursive`-clone, da dieses Repo git-Submodule enthält:

```shell
# create your own fork as usual (example https://sgit.iue.tuwien.ac.at/eXXXXXXXX/exercise5)
git config --global credential.helper "cache --timeout 300"
git clone --recursive https://sgit.iue.tuwien.ac.at/eXXXXXXXX/exercise5.git
git submodule update --init --recursive # important: populates the ./include folder
```

Eine vollständige Sammlung von CMake- und Test-Befehlen finden Sie in [`SNIPPETS.md`](SNIPPETS.md).

---

In dieser Hausübung werden folgende Themen erstmalig einfliessen:

- Arbeiten mit Kollektionen von eindeutigen Werten `std::set<int>`/`std::unordered_set<int>`
- Arbeit mit der öffentlichen Schnittstelle einer gegebenen Klasse
- Nutzung von selbst implementierter Funktionalität in einem separaten Anwendungskontext

---

## Aufgabe 1: Ein eigenes kleines C++-Programm (`std::set`/`std::unordered_set`) (keine Punkte)
**Datei:** `src/task1.main.cpp`

- Definition/Implementierung einer eigenen Funktion `count_unique` in einem eigenen Namensraum `task1`, die eindeutige Werte in einer Sequenz zaehlt.
- Definition/Implementierung einer `main`-Funktion, die Ihre selbst geschriebene Funktion verwendet und die berechneten Ergebnisse in der Konsole ausgibt.
---

## Aufgabe 2: Freie Funktionen zur Selektion von zweidimensionalen Koordinaten (1 Punkt)
**Datei:** `src/task2.cpp`

Die von Ihnen zu implementierenden freien Funktionen selektieren aus einer Koordinatenfolge genau jene Einträge, für die eine zusätzlich übergebene Funktion den Wert `true` liefert.

Die Rückgabe der ausgewählten Koordinaten erfolgt nicht direkt über eine Liste von Koordinatenwerten, sondern indirekt über eine Liste von Indizes.

Hinweis: In Aufgabe 3 werden Sie Ihre Funktionen im Zusammenhang mit der Klasse `iue::msh::Triangles` anwenden.

Implementieren Sie die folgenden freien Funktionen:

```cpp
namespace task2 {

using Vec2d = std::array<double, 2>;
using Circle = std::tuple<Vec2d, double>;
using BBox = std::tuple<Vec2d, Vec2d>;
using Region = std::function<bool(Vec2d)>;

/// @todo
std::unordered_set<size_t> select(const std::vector<Vec2d>& vertices,
								  const Region& region,
								  bool invert = false);
/// @todo
std::unordered_set<size_t> select_union(const std::vector<Vec2d>& vertices,
										const std::vector<Region>& regions,
										bool invert = false);

}
```

**Tests:** Sie können Ihre Implementierung testen, indem Sie `src/task2.test.cpp` kompilieren und ausführen. Diese Datei enthält vorbereitete Assertions, die Ihre Funktionen auf Korrektheit prüfen.


---

## Aufgabe 3: Erzeugen eines Dreiecksgitters für zwei Kreisringe (1 Punkt)
**Datei:** `src/task3.cpp`

Sie implementieren eine Funktion, die mittels der Klasse `iue::msh::Triangles` zuerst ein rechteckiges Dreiecksgitter erstellt, und dann mittels

- der von Ihnen implementierten Funktionen `task2::select`/`task2::select_union` und
- der öffentlichen Schnittstellen der Klasse `iue::msh::Triangles`

Dreiecke aus dem Gitter entfernt, so dass schlussendlich ein Dreiecksgitter nur innerhalb zweier Kreisringe bestehen bleibt.

Implementieren Sie folgende Funktion:

```cpp
#include "iue-msh/triangles.hpp" // iue::msh::Triangles

namespace task3 {

/// @todo
iue::msh::Triangles generate_double_annulus(task2::Vec2d c1,
											task2::Vec2d c2,
											double r,
											double R,
											double h);

}
```

Dies sieht dann abhängig von den Koordinaten der Kreismittelpunkte, Radien und Gitterauflösung z.B. so aus:

![images/annuluses1.svg](images/annuluses1.svg)
![images/annuluses3.svg](images/annuluses3.svg)

**Tests:**  Testen Sie Ihre Implementierung mit `src/task3.test.cpp`. Das erzeugte SVG-Bild landet im `output`-Ordner und kann einfach in jedem modernen Webbrowser geöffnet und betrachtet werden.


---
