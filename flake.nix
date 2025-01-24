{
  description = "umbrella game flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    pkgs = nixpkgs.legacyPackages.x86_64-linux;
    pkgs32 = nixpkgs.legacyPackages.i686-linux;
  in
  {
    devShells.x86_64-linux.default = pkgs.mkShell {
      nativeBuildInputs = with pkgs; [
        gnumake
	cmake
      ];

      buildInputs = with pkgs; [
        imgui
	SDL2
      ];
    };

    devShells.i686-linux.default = pkgs32.mkShell {
      nativeBuildInputs = with pkgs32; [
        gnumake
	cmake
      ];

      buildInputs = with pkgs32; [
        imgui
	SDL2
      ];
    };
  };
}
