# C++ Template for Bazel and ncurses

> Can be used in Visual Studio Code

This is a starter template for building C++ binaries using ncurses library and [Bazel](https://www.bazel.build/) build system.

[ncurses](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html) (new curses) is a  library providing a set of APIs that allows the programmer to write text-based user interfaces in a terminal-independent manner. It is a toolkit for developing "GUI-like" application software that runs under a terminal emulator. It also optimizes screen changes, in order to reduce the latency experienced when using remote shells.

## Screenshot

<img alt="Screenshot" src="https://raw.githubusercontent.com/ourarash/ncurses_hello_world/master/screenshot.gif" width="600">

## Installation

You can copy this using this command:

```bash
git clone https://github.com/ourarash/cpp-template.git
```

### Run main:

You can run this using `blaze`:

```bash
bazel run src/main:main
```

### Run Tests:

You can run unit tests using [`blaze`](installing-bazel):

```bash
bazel test tests:tests
```

## Installing Bazel

This repo uses `Bazel` for building C++ files.
You can install Bazel using this [link](https://docs.bazel.build/versions/master/install.html).

### Credit

This repo was inspired by [this post](https://www.ratanparai.com/c++/writing-unit-tests-with-bazel/).
