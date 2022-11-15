Presupunând că dispunem de o tablă de dimensiune 4x4, o
soluţie ar fi următoarea:
Observăm că o damă trebuie să fie plasată singură pe linie. Plasăm prima
damă pe linia 1, coloana 1.
A doua damă nu poate fi aşezată decât în coloana 3.
Observăm că a treia damă nu poate fi plasată în linia 3. Încercăm atunci
plasarea celei de-a doua dame în coloana 4.
A treia damă nu poate fi plasată decât în coloana 2.

În această situaţie dama a patra nu mai poate fi aşezată.
Încercând să avansăm cu dama a treia, observăm că nu este posibil să o
plasăm nici în coloana 3, nici în coloana 4, deci o vom scoate de pe tablă. Dama
a doua nu mai poate avansa, deci şi ea este scoasă de pe tablă. Avansăm cu
prima damă în coloana 2.
A doua damă nu poate fi aşezată decât în coloana 4.
Dama a treia se aşează în prima coloană.
Acum este posibil să plasăm a patra damă în coloana 3 si astfel am obţinut
o soluţie a problemei.

Algoritmul continuă în acest mod până când trebuie scoasă de pe tablă
prima damă.
Pentru reprezentarea unei soluţii putem folosi un vector cu n componente
(având în vedere că pe fiecare linie se găseşte o singură damă).
Exemplu pentru soluţia găsită avem vectorul ST ce poate fi asimilat unei
stive.
Două dame se găsesc pe aceeaşi diagonală dacă si numai dacă este
îndeplinită condiţia: |st(i)-st(j)|=|i-j| ( diferenţa, în modul, între linii si coloane
este aceeaşi).
ST(4)
ST(3) În general ST(i)=k semnifică faptul că pe linia i dama ocupă poziţia k.
ST(2)
ST(1)
Exemplu: în tabla 4 x4 avem situaţia:
st(1)= 1 i = 1
st(3)= 3 j = 3
|st(1) - st(3)| = |1 – 3| = 2
|i – j| = |1 – 3| = 2
sau situaţia
st(1) = 3 i = 1
st(3) = 1 j = 3
|st(i) - st(j)| = |3 – 1| = 2
|i – j| = |1 – 3| = 2
Întrucât doua dame nu se pot găsi în aceeaşi coloană, rezultă că o soluţie
este sub formă de permutare. O primă idee ne conduce la generarea tuturor
permutărilor si la extragerea soluţiilor pentru problema ca două dame să nu fie
plasate în aceeaşi diagonală. A proceda astfel, înseamnă că lucrăm conform
strategiei backtracking. Aceasta presupune ca imediat ce am găsit două dame
care se atacă, să reluăm căutarea.
lată algoritmul, conform strategiei generate de backtracking:
- În prima poziţie a stivei se încarcă valoarea 1, cu semnificaţia că în linia
unu se aşează prima damă în coloană.
- Linia 2 se încearcă aşezarea damei în coloana 1, acest lucru nefiind
posibil întrucât avem doua dame pe aceeaşi coloană.

- În linia 2 se încearcă aşezarea damei în coloana 2 , însă acest lucru nu
este posibil, pentru că damele se găsesc pe aceiaşi diagonală (|st(1)-st(2)|=|1-2|);
- Aşezarea damei 2 în coloana 3 este posibilă.
- Nu se poate plasa dama 3 în coloana 1, întrucât în liniile 1-3 damele
ocupa acelaşi coloană.
- Şi această încercare eşuează întrucât damele de pe 2 şi 3 sunt pe aceeaşi
diagonală.
- Damele de pe 2-3 se găsesc pe aceeaşi coloană.
- Damele de pe 2-3 se găsesc pe aceeaşi diagonală.
- Am coborât în stivă mutând dama de pe linia 2 şi coloana 3 în coloana 4.
Algoritmul se încheie atunci când stiva este vidă. Semnificaţia procedurilor
utilizate este următoarea:
INIT - nivelul k al stivei este iniţializat cu 0;
ABSOLUT - returnează valoarea absolută a unui întreg;
VALID - validează valoarea pusă pe nivelul k al stivei, verificând dacă nu
avem două dame pe aceeaşi linie (st(k)=st(i)), sau dacă nu avem două dame pe
aceeaşi diagonală (st(k)-st(i)=|k-i|) caz în returnează 1; în caz contrar, în
returnează 0;
SOLUTIE - verifică dacă stiva a fost completată până la nivelul n
inclusiv;
TIPAR - tipăreşte o soluţie.
