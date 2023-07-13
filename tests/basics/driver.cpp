// The following source code was taken mostly verbatim from
// upstream/asio/src/tests/unit/local/connect_pair.cpp.
//
// Because a large proportion of Asio's code is located in header files it's
// not always easy to tell but stepping through this program with a debugger
// confirms that multiple .ipp files are visited which means this program does
// execute code compiled into the library.
//

#include <asio/local/connect_pair.hpp>

#include <asio/io_context.hpp>
#include <asio/local/datagram_protocol.hpp>
#include <asio/local/stream_protocol.hpp>

#ifdef LIBASIO_TESTS_SSL_ENABLED
#include <asio/ssl.hpp>
#endif

int
main ()
{
  using namespace asio;
  namespace local = asio::local;
  typedef local::datagram_protocol dp;
  typedef local::stream_protocol sp;

  try
  {
    asio::io_context io_context;
    asio::error_code ec1;

    dp::socket s1 (io_context);
    dp::socket s2 (io_context);
    local::connect_pair (s1, s2);

    dp::socket s3 (io_context);
    dp::socket s4 (io_context);
    local::connect_pair (s3, s4, ec1);

    sp::socket s5 (io_context);
    sp::socket s6 (io_context);
    local::connect_pair (s5, s6);

    sp::socket s7 (io_context);
    sp::socket s8 (io_context);
    local::connect_pair (s7, s8, ec1);

#ifdef LIBASIO_TESTS_SSL_ENABLED
    asio::ssl::context ssl_ctx (asio::ssl::context::sslv23);
#endif
  }
  catch (std::exception&)
  {
  }

  return 0;
}
