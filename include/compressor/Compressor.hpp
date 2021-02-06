#ifndef COMPRESSOR_H
#define COMPRESSOR_H


namespace compressor{
	class Compressor{
	public:
		virtual void encode() = 0;
		virtual void decode() = 0;
		virtual ~Compressor();
	};
}

#endif