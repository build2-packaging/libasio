#pragma once

#include <iosfwd>
#include <string>

#include <asio/export.hxx>

namespace asio
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  ASIO_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
