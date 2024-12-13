# sdk/include/*.js unit testing how-to
This folder contains tests for the .js code in sdk/include.

## Installing dependencies
1. `cd sdk/tests/include`
2. `npm install`

## Running tests
1. `cd sdk/tests/include`
2. `npm test` – this runs the tests using the [mocha](http://mochajs.org/) test runner.

You should see some output, similar to this:

```
$ npm test

> pebble-pkjs-tests@1.0.0 test /Users/martijn/tintin/sdk/tests/include
> NODE_PATH=../include ./node_modules/mocha/bin/mocha *.js

  Pebble
    interprets received postMessage API data as UTF-8
      ✓ interprets [34,34] as ""
      ✓ interprets [34,240,159,146,169,34] as "💩"
      ✓ interprets [34,237,160,181,237,188,128,34] as {}
      ✓ interprets [34,196,145,34] as "đ"
      ✓ interprets [34,224,160,149,34] as "ࠕ"
    encodes sent postMessage API data as UTF-8
sendAppMessage: [object Object]
      ✓ encodes "" as [34,34,0]
sendAppMessage: [object Object]
      ✓ encodes "💩" as [34,240,159,146,169,34,0]
sendAppMessage: [object Object]
      ✓ encodes "đ" as [34,196,145,34,0]
sendAppMessage: [object Object]
      ✓ encodes "ࠕ" as [34,224,160,149,34,0]

  9 passing (25ms)

```

## Linting the test code

1. `cd sdk/tests/include`
2. `npm run-script lint`

## Adding tests

* You can add `test_xyz.js` files in the `tests` folder. It will automatically get picked up by the test runner.
* If you need to a mock for the global `Pebble` object, check out `pebble-mock.js`. It's probably worth using and extending that than to re-invent the wheel.
* When adding additional dependencies (node packages), make sure to install them using `npm install --save-dev <PACKAGE_NAME>` so that they get added to the `devDependencies` in the `package.json` file.
