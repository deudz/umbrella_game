{
  description = "umbrella game flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in
  {
    devShell.${system} = pkgs.mkShell {
      nativeBuildInputs = with pkgs; [
        gnumake
	cmake
      ];

      buildInputs = with pkgs; [
        imgui
	SDL2
      ];
    };
  };
}
