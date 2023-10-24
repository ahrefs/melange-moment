# melange-moment

[Melange](https://melange.re) bindings for [Moment.js](https://momentjs.com/).

Based on [bs-moment](https://github.com/Jimexist/bs-moment).

## Status

This package is still 🚧 WIP 🚧, but new bindings are added _as needed_ instead of actively. Feel free to create an issue or PR if you find anything missing.

## Installation

Install [opam](https://opam.ocaml.org/) package manager.

Then:

```bash
opam install melange-moment
```

The bindings support the following versions of the `moment`
npm package, which should be installed separately:

```json
  "dependencies": {
    "moment": "^2.26.0"
  }
```

## Setup

Add `melange-moment` to the `libraries` field in your `dune` file:

```clojure
; ...
  (libraries melange-moment)
; ...
```

## Mutations

This binding takes an opinionated approach to mutations, e.g. `moment().add`, `moment().startOf`, and bind them with names like `mutableAdd` and `mutableStartOf`. To compensate that, there's an immutable version named `add` and `startOf` which takes a `moment().clone` first before applying the mutations.

## Deprecations

Deprecated methods (e.g. `moment().days` in favor of `moment().day`) are not included in this binding.
