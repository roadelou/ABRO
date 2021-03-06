# ABRO

The [ABRO program](abro.strl) is the `hello_world` equivalent for the [Esterel Programing Language](https://en.wikipedia.org/wiki/Esterel).

Since most resources on the language has disappeared with time, I tried to write myself in C what a real Esterel compiler could generate for the ABRO program, like a _human compiler_.

The strategy I used for the compilation is that of a finite automaton, but better and more complex strategies can be used, see [this old course from Columbia University](http://www1.cs.columbia.edu/~sedwards/classes/2002/w4995-02/esterel.pdf) for more information.

# Usage

To compile the code, just run `make` from the root of the repository. This should produce a `abro.elf` file in the build directory. From there, you can run the ABRO program wrapped inside of a CLI interface.

An example usage would be:

```
[user@localhost build]$ ./abro.elf
Current signals: (A, 0), (B, 0), (R, 0), (O, 0)
>> A
Current signals: (A, 1), (B, 0), (R, 0), (O, 0)
>> L
Unknown signal L
Current signals: (A, 0), (B, 0), (R, 0), (O, 0)
>> B
Current signals: (A, 0), (B, 1), (R, 0), (O, 0)
>> L
Unknown signal L
Current signals: (A, 0), (B, 0), (R, 0), (O, 1)
>> A
Current signals: (A, 1), (B, 0), (R, 0), (O, 1)
>> R
Current signals: (A, 0), (B, 0), (R, 1), (O, 0)
```

### METADATA

Field | Value
--- | ---
:pencil: Contributors | roadelou
:email: Contacts | 
:date: Creation Date | 2021-03-06
:bulb: Language | Markdown Document

### EOF
