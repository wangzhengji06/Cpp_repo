{
  description = "C/C++ learning environment with Clang";

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

              gnumake
              pkg-config
            ];

            shellHook = ''
              export CC=${clangPkgs.clang}/bin/clang
              export CXX=${clangPkgs.clang}/bin/clang++

              export CLANGD_FLAGS="--query-driver=$CC,$CXX"

              echo "C/C++ dev shell loaded with Clang"
              echo "CC           = $CC"
              echo "CXX          = $CXX"
              echo "CLANGD_FLAGS = $CLANGD_FLAGS"
              $CC --version | head -n 1
            '';
          };
        });
    };
}
