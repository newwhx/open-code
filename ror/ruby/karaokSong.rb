class KaraokSong < Song
	def initialize(name, artist, duration, lyrics)
		super(name, artist, duration)
		@lyrics = lyrics
	end

	def to_s
		super + ", and the lyrics is :#@lyrics"
	end
end
