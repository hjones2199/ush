{
  description = "A flake for building ush";

  inputs.nixpkgs.url = github:NixOS/nixpkgs/nixos-unstable;

  outputs = { self, nixpkgs }: {
    defaultPackage.x86_64-linux =
      with import nixpkgs { system = "x86_64-linux"; };
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
          license = licenses.bsd3;
          maintainers = with maintainers; [ hjones2199 ];
        };
      };
  };
}
