use std::env;

/* 
  On my system:

  root@kalilinux:~/misc/common_ds# RUST_BACKTRACE=full ./factorial 35
thread 'main' panicked at 'attempt to multiply with overflow', factorial.rs:17:9
stack backtrace:
   0:     0x55bec1521f3b - backtrace::backtrace::libunwind::trace::hfe5db90796807973
                               at /cargo/registry/src/github.com-1ecc6299db9ec823/backtrace-0.3.29/src/backtrace/libunwind.rs:88
   1:     0x55bec1521f3b - backtrace::backtrace::trace_unsynchronized::h34b865a835594335
                               at /cargo/registry/src/github.com-1ecc6299db9ec823/backtrace-0.3.29/src/backtrace/mod.rs:66
   2:     0x55bec1521f3b - std::sys_common::backtrace::_print::h527254ae44989167
                               at src/libstd/sys_common/backtrace.rs:47
   3:     0x55bec1521f3b - std::sys_common::backtrace::print::he85dd5ddddf46503
                               at src/libstd/sys_common/backtrace.rs:36
   4:     0x55bec1521f3b - std::panicking::default_hook::{{closure}}::h847a2eb38b396f14
                               at src/libstd/panicking.rs:200
   5:     0x55bec1521c17 - std::panicking::default_hook::h2ca0f9a30a0e206b
                               at src/libstd/panicking.rs:214
   6:     0x55bec1522600 - std::panicking::rust_panic_with_hook::hffcefc09751839d1
                               at src/libstd/panicking.rs:477
   7:     0x55bec1522182 - std::panicking::continue_panic_fmt::hc0f142c930c846fc
                               at src/libstd/panicking.rs:384
   8:     0x55bec1522066 - rust_begin_unwind
                               at src/libstd/panicking.rs:311
   9:     0x55bec153612d - core::panicking::panic_fmt::h2daf88b2616ca2b2
                               at src/libcore/panicking.rs:85
  10:     0x55bec153606c - core::panicking::panic::h2d0bc53a963fb996
                               at src/libcore/panicking.rs:49
  11:     0x55bec1518e6d - factorial::factorial_iterative::hc06c0ee47d26cbce
  12:     0x55bec1518f61 - factorial::main::h11e769eaa361a865
  13:     0x55bec1516e43 - std::rt::lang_start::{{closure}}::h1a6f6af7dc1fbdc8
  14:     0x55bec1522053 - std::rt::lang_start_internal::{{closure}}::h447d8812e3ee306d
                               at src/libstd/rt.rs:49
  15:     0x55bec1522053 - std::panicking::try::do_call::h4a61cb372364c745
                               at src/libstd/panicking.rs:296
  16:     0x55bec152381a - __rust_maybe_catch_panic
                               at src/libpanic_unwind/lib.rs:82
  17:     0x55bec1522b0d - std::panicking::try::hdf71f938885bca42
                               at src/libstd/panicking.rs:275
  18:     0x55bec1522b0d - std::panic::catch_unwind::h7e85dbf162b1611a
                               at src/libstd/panic.rs:394
  19:     0x55bec1522b0d - std::rt::lang_start_internal::h1e06cc26b9fc25ea
                               at src/libstd/rt.rs:48
  20:     0x55bec1516e25 - std::rt::lang_start::hdde5b5a57ad9537b
  21:     0x55bec15190bb - main
  22:     0x7f139692309b - __libc_start_main
  23:     0x55bec151417a - _start
  24:                0x0 - <unknown>


 */

#[allow(dead_code)]
fn factorial(n: u128) -> u128 {
    if n == 0 || n == 1 {
        return 1;
    }

    n * factorial(n-1)
}

fn factorial_iterative(n: u128) -> u128 {
    let mut final_result = 1;
    let mut local_n = n;

    while local_n > 1 {
        final_result *= local_n;
        local_n-=1;
    }

    return final_result;
}

fn main()  {
    let args: Vec<String> = env::args().collect();

    let n_str = &args[1]; // check for lenght of args -> too lazy to do id :)
    let n_int = n_str.parse::<u128>().unwrap(); // will explode if not a valid integer is passed
    println!("{}! = {}", n_int, factorial_iterative(n_int)); // change here if you want iterative or recursive factorial()
}
