# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, inputs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
      inputs.home-manager.nixosModules.default
    ];

  # Bootloader.
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  networking.hostName = "nixos"; # Define your hostname.
  # networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.

  # Configure network proxy if necessary
  # networking.proxy.default = "http://user:password@proxy:port/";
  # networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";

  # Enable networking
  networking.networkmanager.enable = true;
  networking.nameservers = [ "1.1.1.1" ];


  # Set your time zone.
  time.timeZone = "Europe/Budapest";
  nix.settings.experimental-features = ["nix-command" "flakes"];

  # Select internationalisation properties.
  i18n.defaultLocale = "en_US.UTF-8";

  i18n.extraLocaleSettings = {
    LC_ADDRESS = "hu_HU.UTF-8";
    LC_IDENTIFICATION = "hu_HU.UTF-8";
    LC_MEASUREMENT = "hu_HU.UTF-8";
    LC_MONETARY = "hu_HU.UTF-8";
    LC_NAME = "hu_HU.UTF-8";
    LC_NUMERIC = "hu_HU.UTF-8";
    LC_PAPER = "hu_HU.UTF-8";
    LC_TELEPHONE = "hu_HU.UTF-8";
    LC_TIME = "hu_HU.UTF-8";
  };

  # Configure keymap in X11
  services.xserver = {
    xkb.layout = "hu";
    xkb.variant = "";
  };

  # Configure console keymap
  console.keyMap = "hu";

  # Define a user account. Don't forget to set a password with ‘passwd’.
  users.users.thenothingdude = {
    isNormalUser = true;
    description = "TheNothingDude";
    extraGroups = [ "networkmanager" "wheel" ];
    packages = with pkgs; [];
  };
  home-manager = {
  extraSpecialArgs = {inherit inputs;};
  users = {
    		"thenothingdude" = import ./home.nix;
  	};
  };
  #Audio
  security.rtkit.enable = true;
  services.pipewire = {
  	enable = true;
  	alsa.enable = true;
  	alsa.support32Bit = true;
  	pulse.enable = true;
  # If you want to use JACK applications, uncomment this
  	jack.enable = true;
};

  # Allow unfree packages
  security.polkit.enable = true;
  nixpkgs.config.allowUnfree = true;
  services.xserver.videoDrivers = ["amdgpu"];
  hardware.opengl = {
 	driSupport = true;
	driSupport32Bit = true;
	extraPackages = with pkgs; [
			rocm-opencl-icd
			rocm-opencl-runtime
		];
  };
  services.gvfs.enable = true;
  # Shell
  programs.fish.enable = true;
  users.defaultUserShell = pkgs.fish;
  #programs
  programs.steam.enable = true;
  programs.hyprland.enable = true;
  programs.hyprland.xwayland.enable = true;
  xdg.portal = {
	enable = true;
	extraPortals = [pkgs.xdg-desktop-portal-hyprland];
  };
  programs.thunar.enable = true;
  programs.neovim = {
	enable = true;
	defaultEditor = true;
  };
  # env
  environment.sessionVariables = {
	NIXOS_OZONE_WL = "1";
  };
  system.autoUpgrade = {
  enable = true;
  flake = "/etc/nixos#default";
  flags = [
    "--update-input"
    "nixpkgs"
    "-L" # print build logs
   ];
   dates = "9:00";
   randomizedDelaySec = "45min";
  };
  # List packages installed in system profile. To search, run:
  # $ nix search wget
  # install
  environment.systemPackages = with pkgs; [
    unzip 
    unrar
    osu-lazer
    python3Full
    vscodium
    onlyoffice-bin
    qbittorrent
    libnotify
    lutris
    gamemode
    gamescope
    mangohud
    wineWowPackages.staging
    starship
    btop
    tofi
    dunst
    dust
    zoxide
    eza
    zoxide
    waypaper
    swaybg
    pavucontrol
    polkit-kde-agent
    kitty
    waybar 
    git
    neofetch
    brave
  ];
  fonts.packages = with pkgs; [
        vistafonts
	corefonts
	font-awesome
  	(nerdfonts.override { fonts = [ "JetBrainsMono" ]; })
  ];

  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
  # programs.mtr.enable = true;
  # programs.gnupg.agent = {
  #   enable = true;
  #   enableSSHSupport = true;
  # };

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  # Open ports in the firewall.
  # networking.firewall.allowedTCPPorts = [ ... ];
  # networking.firewall.allowedUDPPorts = [ ... ];
  # Or disable the firewall altogether.
  # networking.firewall.enable = false;

  # This value determines the NixOS release from which the default
  # settings for stateful data, like file locations and database versions
  # on your system were taken. It‘s perfectly fine and recommended to leave
  # this value at the release version of the first install of this system.
  # Before changing this value read the documentation for this option
  # (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).
  system.stateVersion = "23.11"; # Did you read the comment?

}
