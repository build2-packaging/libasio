./: {*/ -build/ -upstream/} doc{README PACKAGE-README.md} \
  legal{LICENSE_1_0.txt COPYING} manifest

# Don't install tests.
#
tests/: install = false
