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
  boot.loader = {
   efi = {
      canTouchEfiVariables = true;
 };
   grub = {
        efiSupport = true;
     	device = "nodev";
	useOSProber = true;
  };
 };
  #Kernel
  boot.kernelPackages = pkgs.linuxPackages_latest;

  networking.hostName = "nixpc"; # Define your hostname.
  # networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.

  # Configure network proxy if necessary
  # networking.proxy.default = "http://user:password@proxy:port/";
  # networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";

  # Enable networking
  networking.networkmanager.enable = true;
  #Sleep
    services.xserver.displayManager.gdm.autoSuspend = false;
  systemd.targets.sleep.enable = false;
  systemd.targets.suspend.enable = false;
  systemd.targets.hibernate.enable = false;
  systemd.targets.hybrid-sleep.enable = false;
 
  home-manager = {
  # also pass inputs to home-manager modules
  extraSpecialArgs = {inherit inputs;};
  users = {
    "thenothingdude" = import ./home.nix;
   };
  };

  # Set your time zone.
  time.timeZone = "Europe/Budapest";

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
  i18n.inputMethod.enable = true;
  i18n.inputMethod.type = "fcitx5";
  i18n.inputMethod.fcitx5.addons = [
      pkgs.fcitx5-mozc
      pkgs.fcitx5-gtk
      pkgs.fcitx5-configtool
    ];
  # Enable the X11 windowing system.
  services.xserver.enable = true;
  nix.settings.experimental-features = ["nix-command" "flakes"];
  # Enable the GNOME Desktop Environment.
  services.xserver.displayManager.gdm.enable = true;
  services.xserver.desktopManager.gnome.enable = true;
  #KDE
  #services.displayManager.sddm.enable = true;
  #services.desktopManager.plasma6.enable = true;
  environment.variables = {
    SGI_TYPELIB_PATH = "/run/current-system/sw/lib/girepository-1.0";
    GLFW_IM_MODULE = "ibus";
  };
  #KDE remove pkgs
  #environment.plasma6.excludePackages = with pkgs.kdePackages; [
  #plasma-browser-integration
  #konsole
  #oxygen
  #];
  #Gnome remove pkgs
  environment.gnome.excludePackages = (with pkgs; [
  	gnome-photos
  	gnome-tour
        gedit
	cheese # webcam tool
  	geary
        gnome-music
  	epiphany # web browser
  	geary # email reader
  	evince # document viewer
  	gnome-characters
  	totem # video player
  	tali # poker game
  	iagno # go game
  	hitori # sudoku game
  	atomix # puzzle game
	gnome-console
	gnome-clocks

  ]) ++ (with pkgs.gnome; [
  	]);
  #Hyprland
  programs.hyprland.enable = true;
  #programs.hyprland.package = inputs.hyprland.packages."${pkgs.system}".hyprland;
  programs.hyprland.xwayland.enable = true;
  xdg.portal.enable = true;
  # Configure keymap in X11
  services.xserver.xkb = {
    layout = "hu,jp";
    variant = "";
  };

  # Configure console keymap
  console.keyMap = "hu";

  programs.nix-ld.enable = true;
  programs.nix-ld.libraries = with pkgs; [
  ];

  # Enable sound with pipewire.
  services.pulseaudio.enable = false;
  security.rtkit.enable = true;
  services.pipewire = {
    enable = true;
    alsa.enable = true;
    alsa.support32Bit = true;
    pulse.enable = true;
    # If you want to use JACK applications, uncomment this
    #jack.enable = true;

    # use the example session manager (no others are packaged yet so this is enabled by default,
    # no need to redefine it in your config for now)
    #media-session.enable = true;
  };

  # Enable touchpad support (enabled default in most desktopManager).
  # services.xserver.libinput.enable = true;

  # Define a user account. Don't forget to set a password with ‘passwd’.
  users.users.thenothingdude = {
    isNormalUser = true;
    description = "TheNothingDude";
    extraGroups = [ "networkmanager" "wheel" ];
    packages = with pkgs; [
    #  thunderbird
    ];
  };
  #lact
  systemd.packages = with pkgs; [ lact ];
  systemd.services.lactd.wantedBy = ["multi-user.target"];
  #zsh
  users.defaultUserShell = pkgs.zsh;
  programs.thunar.enable = true;
  programs.zsh.enable = true;
  # Allow unfree packages
  nixpkgs.config.allowUnfree = true;
  services.gvfs.enable = true; # Mount, trash, and other functionalities
  services.tumbler.enable = true; # Thumbnail support for images
  programs.thunar.plugins = with pkgs.xfce; [
   thunar-archive-plugin
 ];
  nixpkgs.config.permittedInsecurePackages = [
	"dotnet-runtime-6.0.36"
	"dotnet-sdk-wrapped-6.0.428"
	"dotnet-sdk-6.0.428"
  ];

  environment.systemPackages = with pkgs; [
    waybar
    waypaper
    swww
    rofi-wayland
    wallust
    swaynotificationcenter
    ciscoPacketTracer8
    anki
    onlyoffice-desktopeditors
    discord
    wget
    unrar
    unzip
    osu-lazer-bin
    heroic
    winetricks
    wineWowPackages.stable
    polkit_gnome
    pavucontrol
    python3
    vscodium
    neovim
    bottles
    brave
    kitty
    git
    gnome-tweaks
    mangohud
    protonup
    protonup-qt
    nh
    fastfetch
    zsh-fzf-tab
    qbittorrent
    dust
    lact
    #Gnome extensions
    gnomeExtensions.kimpanel
    gnomeExtensions.spotify-tray
    gnomeExtensions.blur-my-shell
    gnomeExtensions.appindicator
    gnomeExtensions.vitals
  ];
  # Fonts
  fonts.packages = with pkgs; [
   corefonts
   nerd-fonts.jetbrains-mono
   vistafonts
   ipafont
   noto-fonts-cjk-sans
   noto-fonts-cjk-serif
   noto-fonts 
   noto-fonts-extra
  ];
  # Flatpak
  services.flatpak.enable = true;
  # gaming
   #env
   environment.sessionVariables = {
    STEAM_EXTRA_COMPAT_TOOLS_PATHS =
      "\${HOME}/.steam/root/compatibilitytools.d";
    FLAKE = "/etc/nixos";
    NIXOS_OZONE_WL = "1";
  };
  programs.steam.enable = true;
  programs.steam.gamescopeSession.enable = true;
  programs.gamescope.enable = true;
  programs.gamemode.enable = true;
  hardware.opentabletdriver.enable = true; 
  hardware.graphics = {
    enable = true;
    enable32Bit = true;
  };

  services.xserver.videoDrivers = ["amdgpu"];
  #Jap
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
  system.stateVersion = "24.05"; # Did you read the comment?

}
