# libasio

Asio is a cross-platform C++ library for network and low-level I/O programming
that provides developers with a consistent asynchronous model using a modern
C++ approach.

Asio provides the basic building blocks for C++ networking, concurrency and
other kinds of I/O. Asio is used in all kinds of applications, from phone apps
to the world’s fastest share markets.

For more information see: https://think-async.com/Asio/

This is a `build2` package for the standalone version of the Asio library.

# Usage

This package provides the `lib{asio}` library.

SSL support is disabled by default. To enable it, add the following to your
`manifest`:

```
depends:
\
libasio ^1.28.0
{
  require
  {
    config.libasio.ssl = true
  }
}
\
```

Note that on some platforms (such as MinGW) it may be necessary for
applications to define `_WIN32_WINNT` to an appropriate value. If it's not
defined the library's `config.hpp` header will issue a warning and choose a
default (currently `0x0601`, meaning Windows 7 and later; this is also the
value that the library is built with).
