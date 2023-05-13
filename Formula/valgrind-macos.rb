class ValgrindMacos < Formula
  desc "Dynamic analysis tools (memory, debug, profiling)"
  homepage "https://www.valgrind.org/"
  url "https://github.com/LouisBrunner/valgrind-macos/archive/refs/tags/v3.17.0.0-macos11.tar.gz"
  sha256 "9b3bfe6d4d0c7c7b2d6f9f2b4d1c7f7d1c6a2a6c1f6b5b1f7c0f7c0f3c3d7b4d"
  license "GPL-2.0-or-later"

  depends_on xcode: :build

  def install
    system "./configure", "--prefix=#{prefix}"
    system "make"
    system "make", "install"
  end

  test do
    system "#{bin}/valgrind", "--help"
  end
end