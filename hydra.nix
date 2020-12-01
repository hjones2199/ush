{ ... }:

let
  pkgs = (import <nixpkgs> {});
in
{
  ush = pkgs.callPackage ./ush.nix { };
}
