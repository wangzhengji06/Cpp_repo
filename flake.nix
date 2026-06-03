{
  description = "C/C++ learning environment with Clang and Qt";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { nixpkgs, ... }:
    let
      lib = nixpkgs.lib;
      forAllSystems = lib.genAttrs lib.systems.flakeExposed;
    in
    {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgs.legacyPackages.${system};

          clangPkgs = pkgs.llvmPackages_19;
        in
        {
          default = pkgs.mkShell.override {
            stdenv = pkgs.clangStdenv;
          } {
            nativeBuildInputs = with pkgs; [
              clangPkgs.clang
              clangPkgs.clang-tools
              clangPkgs.lldb

              cmake
              gnumake
              pkg-config

              qt6.wrapQtAppsHook
            ];

            buildInputs = with pkgs; [
              qt6.qtbase
              qt6.qttools
            ];

            shellHook = ''
              export CC=${clangPkgs.clang}/bin/clang
              export CXX=${clangPkgs.clang}/bin/clang++

              export CLANGD_FLAGS="--query-driver=$CC,$CXX"

              export CMAKE_PREFIX_PATH=${pkgs.qt6.qtbase}

              echo "C/C++ dev shell loaded with Clang and Qt"
              echo "CC           = $CC"
              echo "CXX          = $CXX"
              echo "CLANGD_FLAGS = $CLANGD_FLAGS"
              echo "Qt version:"
              ${pkgs.qt6.qtbase}/bin/qmake --version | head -n 2
              $CC --version | head -n 1
            '';
          };
        });
    };
}