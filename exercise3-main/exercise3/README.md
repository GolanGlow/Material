# Hausübung 3 (2 Punkte)

**Ausgabe**: Dienstag 24. März 2026, vormittags.

**Abgabe bis**: Montag 13. April 2026, Ende des Tages.

**Abgabe via**: git-Repository mit dem Namen **`exercise3`** auf unserem git-Server https://sgit.iue.tuwien.ac.at

```shell
# create your own fork as ususal (example https://sgit.iue.tuwien.ac.at/eXXXXXXXX/exercise3)
git config --global credential.helper "cache --timeout 300"
git clone https://sgit.iue.tuwien.ac.at/eXXXXXXXX/exercise3.git
git submodule update --init --recursive # important: populates the ./include folder
```


---

Dieses Hausuebung führt in die numerische Berechnung und Visualisierung von Funktionen ein. 
Die Aufgaben fuehren (schrittweise) von einfachen Vektoroperationen bis zur numerischen Differentiation und Integration sowie der Visualisierung der Ergebnisse.

Als Vorwissen wird von diesen Hausuebungen aus 360.058 ausgegangen:
  - Numerische Differenzierung: https://sgit.iue.tuwien.ac.at/360058/homework7 
  - Numerische Integration: https://sgit.iue.tuwien.ac.at/360058/homework10

Zum Schreiben/Lesen von CSV-Dateien wird diese Bibliothek eingesetzt:
- https://sgit.iue.tuwien.ac.at/360062/include/src/branch/main/iue-io/csv.hpp
- Diese Bibliothek ist als Git-Submodul in `include/` eingetragen, und muss mittels folgendem Befehl initialisiert werden: 

  `git submodule update --init --recursive`

---

## Task 1: Grundlegende Vektoroperationen (keine Punkte)

In der ersten Aufgabe lernen Sie den Umgang mit verschachtelten Vektoren (`std::vector<std::vector<int>>`) kennen. 
Das Ziel ist die Implementierung einer Funktion, die die Summe aller ganzzahligen Werte in einer Menge von Sequenzen berechnet.

**Ziel:**
- Erstellen Sie eine `sum`-Funktion, die alle Elemente einer verschachtelten Vektorstruktur addiert
- Testen Sie die Funktion mit einer 3×3-Matrix:
  ```
  [1, 2, 3]
  [4, 5, 6]
  [7, 8, 9]
  ```
- Das erwartete Ergebnis ist **45**

**Implementierung:**
- Die Funktion muss sicherstellen, dass zumindest ein Wert vorhanden ist (assertion)
- Iteration über alle Werte (Zeilen und Spalten), um die Werte zu akkumulieren.

---

## Task 2: Numerische Methoden (1 Punkt)

Sie implementieren fundamentale numerische Methoden zur Diskretisierung, Differentiation und Integration von Funktionen:

#### `range(start, end, n)`
Erzeugt eine äquidistante Folge von Werten in einem gegebenen Intervall (inklusive der Grenzwerte):
- **Parameter**: `start` (Startpunkt), `end` (Endpunkt), `n` (Anzahl der Werte, n ≥ 2)
- **Rückgabe-Tupel**: `{Vektor der Werte, Schrittweite dx}`

#### `sample(values, func)`
Wertet eine eindimensionale skalare Funktion an diskreten Positionen aus:
- **Parameter**: `values` (Folge von Positionen), `func` (Funktion mit Signatur `f(double) -> double`)
- **Rückgabe**: Folge der Funktionswerte

#### `numdiff(y, dx)`
Führt eine numerische Differentiation durch:
- **Parameter**: `y` (Funktionswerte), `dx` (Schrittweite)
- **Rückgabe**: Folge der numerischen Ableitungswerte

Intern wird für die Differentiation ein kombiniertes Schema eingesetzt:
- Vorwärtsdifferenze für den ersten Wert
- Rückwärtsdifferenze für den letzten Wert
- Zentraldifferenze für alle anderen Werte

#### `numint(y, dx)`
Berechnet numerisch das bestimmte Integral ueber ein Intervall mittels der Trapezregel:
- **Parameter**: `y` (diskrete Funktionswerte des Intervalls), `dx` (Schrittweite)
- **Rückgabe**: Werte des Integrals (Integrationkonstante = 0)

**Testen:**
Die Tests in `task2.test.cpp` verifizieren Ihre Implementierung für verschiedene Funktionen (z.B. Sinus, Cosinus, lineare Funktionen).

---

## Task 3: Funktionssampling und Visualisierung (1 Punkt)

Die dritte Aufgabe kombiniert C++ und Python.
Sie implementieren Funktionen 
- zur Generierung von diskreten Funktionswerten und 
- zur Visualisierung dieser Daten.

### Diskrete Funktionswerte erzeugen

Die Funktion `sample_derivate_and_antiderivative_to_csv()` erhaelt folgende Parameter
- `func` (Funktion mit Signatur `f(double) -> double`)
- `interval` Start- und Endwert des Intervalls
- `n` Anzahl an diskreten Stellen fuer die Abtastung
- `filepath` Pfad fuer die CSV-Datei
- `del` Trennzeichen fuer die CSV-Datei

... und erzeugt daraus eine CSV-Datei mit folgenden Spalten:

| Spalte | Beschreibung |
|--------|--------------|
| $x$ | Diskrete Position |
| $f(x)$ | Funktionswert |
| $\int_{x=start}^{x} f(x)$ | Numerisches Integral |
| $df(x)$ | Numerische Ableitung |

**Implementierungshinweise:**
1. Verwenden Sie `range()` und `sample()` zur Abtasten der Funktion
2. Berechnen Sie die numerische Ableitung mit `numdiff()`
3. Berechnen Sie das numerische Integral mit `numint()`
4. Nutzen Sie `iue::io::savecsv()` zum Schreiben der CSV-Datei 

**Testen:**
Die Tests in `task3.test.cpp` erzeugen CSV-Dateien für $sin(x)$ und $cos(x)$ im Intervall $[0, 2\pi]$ und verifizieren das Ergebnis.

### Visualisierung der diskreten Werte

Die Python-Funktion `plot_discrete_function()` liest eine generierte CSV-Datei und visualisiert alle drei Funktionen in einem einzigen Diagramm.

**Anforderungen an den Plot:**
- Achsenbeschriftungen ("x" und "y")
- Legende für alle drei Datenreihen
- Speichern des Plots als PNG-Datei

**Implementierungshinweise:**
- Verwenden Sie `numpy.loadtxt()` zum Laden der CSV-Daten
- Verwenden Sie `matplotlib` für die Visualisierung

---

