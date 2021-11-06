{
  description = "A flake for building ush";

  inputs.nixpkgs.url = github:NixOS/nixpkgs/nixos-unstable;
  inputs.flake-utils.url = github:numtide/flake-utils;

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system}; in
      rec {
        defaultPackage = with pkgs;
          stdenv.mkDerivation rec {
            pname = "ush";
            version = "0.72";

            src = self;

            nativeBuildInputs = [
              meson
              ninja
              pkg-config
            ];

            buildInputs = [ libedit ];

            meta = with lib; {
              description = "small personal shell";
              homepage = "https://qirus.net";
              maintainers = with maintainers; [ hjones2199 ];
              license = licenses.bsd3;
              platforms = platforms.unix;
            };
          };
      }
    );
}
