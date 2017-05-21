# SchemePlusPlus
A simple and fun Scheme interpreter written in C++ (C++11). 

Scheme is a simple but powerful functional language first developed in the 1990s at MIT. I've enjoyed reading Peter Norvig's blog [(How to Write a (Lisp) Interpreter (in Python))](http://norvig.com/lispy.html), in which he writes a Scheme interpreter in 90+ lines of Python. The C++ implementation is a bit more challenging and I thought I'd give it a try. 

UC Berkley's [CS61A: Structure and Interpretation of Computer Programs](https://cs61a.org) has also been very helpful.


## Core Concepts

The interpreter is divided into 2 parts.

```
1. Parsing (Lexical Analysis)
  - Read input program
  - Break program into tokens (internal representation)
  - Analysis of tokens according our Abstract Syntax Tree
2. Evaluation & Execution 
  - Internal representation is processed according to the semantics of Scheme
  - Carry out the computation
```

Overview of internal processes
```
Program => Parse => Abstract Syntax Tree => eval => result
```

### Prerequisites

```
GNU GCC (C++11)
```

### Installing

To clone this repo to your local machine:
```
git clone
```

*note Windows users must install cygwin

Compile and Run:
```
cd SchemePlusPlus
make build
```
## Representation of Scheme objects in C++

## List of Supported Scheme Expressions

## Files

## Example Scheme Programs

## Running Tests

## Contributing

Feel free to contribute and/or create new issues

## Versioning

I use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/jsun98/SchemePlusPlus/tags). 

## Authors

* **Joshua Sun** - [github](https://github.com/jsun98)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Peter Norvig, Director of Research, Google Inc.

