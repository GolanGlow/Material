# Labor II: Abgabe (30min)

Angabe siehe TUWEL-Seite des Kurses.

# Labor II: Praxisteil (120min)

Im heutigen Labor sollen Sie die folgenden drei Aufgabengebiete bearbeiten. 

- Klassen: Mehrere Konstruktoren
- Klassen: Memberfunktionen und public/private Membervariablen
- Überladen von Operatoren und Lambda-Funktionen

---

## A. Klassen mit mehreren Konstruktoren

In der Datei [src/taskA.cpp](src/taskA.cpp) sind zwei Klassen `Point2D` und `Point3D` gegeben, die einen Punkt im zwei- bzw. dreidimensionalen Raum darstellen.

**Aufgabe (Details siehe [src/taskA.cpp](src/taskA.cpp)):**

Implementieren Sie mehrere Konstruktoren:
- `Point2D`: **Einschränkung: Alle Konstruktoren sollen eine Initialisierungsliste verwenden.**
  - Ein Wert, der für beide Koordinaten gesetzt wird, wird übergeben.
  - Zwei Werte für die jeweiligen Koordinaten werden übergeben.
  - Ein `std::array` mit Länge 2 wird übergeben.
- `Point3D`: Keine Einschränkung
  - Analog zu `Point2D` und zusätzlich
  - Eine Instanz eines `Point2D` für die x-y-Koordinate und ein weiterer Wert (Default ist `0.0`) für die z-Koordinate werden übergeben.

**Demonstration:** Was sind Vorteile einer Initialisierungsliste? Wie entscheidet der Compiler welcher Konstruktor verwendet werden soll?

## B. Klassen mit Member-Funktionen und public/private Member-Variablen

In der Datei [src/taskB.cpp](src/taskB.cpp) sind zwei *namespaces* `one` und `two` gegeben. In `namespace one` ist eine Klasse `Particle` mit drei Member-Variablen (Geschwindigkeit in x- und y-Richtung und Masse), welche ein Partikel darstellen soll, gegeben.

**Aufgabe (Details siehe [src/taskB.cpp](src/taskB.cpp)):**
  - Erweitern Sie die Klasse `Particle` in `namespace one` um folgende Member-Funktionen: `energy()`, `str()`
  - Erstellen Sie die Klasse `Particle` in `namespace two` mit folgenden Eigenschaften: 
    - Gleiche Member-Variablen wie die Klasse in `namespace one`, diese sollen aber **privat** sein.
    - Konstruktor mit x-, y-Richtung und Masse als Parameter.
    - Member-Funktionen: `set()`, `get()`, `energy()`, `str()`.
  
  - In der `main` Funktion:
    - Erstellen Sie jeweils eine Instanz der beiden Klassen und rufen Sie alle Member-Funktionen auf.

**Hinweis:**
  - Formel für die kinetische Energie: $E_{kin} = \frac{1}{2} \cdot m \cdot (v_x^2 + v_y^2)$


**Demonstration:**  Erklären Sie den Unterschied zwischen `struct` und `class`. Was bedeutet `public` bzw. `private` in diesem Zusammenhang und warum werden die Funktionen `get()` und `set()` eingeführt?

## C. Überladen von Operatoren und Lambda-Funktionen

Sie sollen eine Klasse implementieren um Polynome der Form $f(x) = a_0x^0 + a_1x^1 + a_2x^2$ darzustellen.\
Das Verwenden der Klasse könnte dann in etwa so aussehen:


```cpp
int main(){
  auto [a0, a1, a2] = std::tuple<double, double, double>{1.0, 2.0, 3.0};  // given coefficients
  auto p1 = PolyOrder2(a0, a1, a2);   // this represents the polynomial f(x) = 1.0 + 2.0*x + 3.0*x**2
  double res = p1(1.0);  // using overloaded operator '()' to evaluate 'p1' at x = 1.0
                         // equivalent to: res = p1.operator()(x)
  std::cout << res << std::endl;
}
```

**Aufgabe (Details siehe [src/taskC.cpp](src/taskC.cpp)):**
  - Erstellen Sie eine Klasse `PolyOrder2` mit folgenden Eigenschaften:
    - Member-Variable(n), die die drei gegebenen Koeffizienten $a_i$ des Polynoms beinhaltet.
    - Konstruktor, der die Koeffizienten mit den übergebenen Werten initialisiert.
    - Member-Funktion `print()`.
    - Überladener Operator `operator()` zum Evaluieren des Polynoms an einer Stelle `x`.
  
  - In der `main` Funktion:
    - Erstellen Sie eine Instanz der Klasse `PolyOrder2`, rufen Sie die `print()` Funktion auf und verwenden Sie den `()` Operator um das Polynom zu evaluieren.

    - Erstellen Sie eine Lambda-Funktion, die ebenfalls ein Polynom derselben Form auswertet:
      - Die Koeffizienten sollen aus dem *scope* der `main()` Funktion aufgenommen werden.
      - Die Stelle der Evaluierung soll als Parameter übergeben werden.

**Demonstration:** Nennen Sie Vor- und Nachteile von Operator Überladungen gegenüber Member-Funktionen. Erklären Sie die Bedeutung eines *scopes* im Zusammenhang mit Lambda-Funktionen.
