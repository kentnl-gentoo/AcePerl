package Ace::Graphics::GlyphFactory;
# parameters for creating sequence glyphs of various sorts
# you *do* like glyphs, don't you?

use strict;
use Carp 'carp';
use Ace::Graphics::Glyph;
use GD;

sub DESTROY { }

sub new {
  my $class   = shift;
  my $type    = shift;
  my @options = @_;

  my $glyphclass = 'Ace::Graphics::Glyph';
  $glyphclass .= "\:\:$type" if $type;

  unless (eval "require $glyphclass") {
    # default to generic
    carp $@;
    carp "$glyphclass could not be loaded, using default";
    $glyphclass = 'Ace::Graphics::Glyph';
  }

  # normalize options
  my %options;
  while (my($key,$value) = splice (@options,0,2)) {
    $key =~ s/^-//;
    $options{lc $key} = $value;
  }
  $options{bgcolor}   ||= 'white';
  $options{fgcolor}   ||= 'black';
  $options{fillcolor} ||= 'turquoise';
  $options{height}    ||= 10;

  return bless {
		glyphclass => $glyphclass,
		font       => gdSmallFont,
		scale      => 1,   # 1 pixel per kb
		options    => \%options,
	       },$class;
}

# set the scale for glyphs we create
sub scale {
  my $self = shift;
  my $g = $self->{scale};
  $self->{scale} = shift if @_;
  $g;
}

sub width {
  my $self = shift;
  my $g = $self->{width};
  $self->{width} = shift if @_;
  $g;
}

# font to draw with
sub font {
  my $self = shift;
  my $g = $self->{font};
  $self->{font} = shift if @_;
  $g;
}

# set the height for glyphs we create
sub height {
  my $self = shift;
  $self->option('height',@_);
}

# set the color translation table
sub color_translations {
  my $self = shift;
  my $g = $self->{translations};
  $self->{translations} = shift if @_;
  $g;
}

sub options {
  my $self = shift;
  my $g = $self->{options};
  $self->{options} = shift if @_;
  $g;
}

sub option {
  my $self        = shift;
  my $option_name = shift;
  my $o = $self->{options} or return;
  my $d = $o->{$option_name};
  $o->{$option_name} = shift if @_;
  $d;
}

# set the foreground and background colors
# expressed as GD color indices
sub fgcolor {
  my $self = shift;
  $self->translate($self->option('fgcolor',@_));
}

sub bgcolor {
  my $self = shift;
  $self->translate($self->option('bgcolor',@_));
}

sub fillcolor {
  my $self = shift;
  $self->translate($self->option('fillcolor',@_));
}

sub length {  shift->option('length',@_) }
sub offset {  shift->option('offset',@_) }

sub translate {
  my $self = shift;
  my $color = shift;
  my $table = $self->{translations} or return $self->fgcolor;
  return defined $table->{$color} ? $table->{$color} : $self->fgcolor;
}

# create a new glyph from configuration
sub glyph {
  my $self    = shift;
  my $feature = shift;
  return $self->{glyphclass}->new(-feature => $feature,
				  -factory => $self);
}

1;
