with import <nixpkgs> {};

stdenv.mkDerivation rec {
  pname = "ush";
  version = "0.72";

  src = ./.;

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
}
