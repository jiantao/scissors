
#ifndef SRC_UTILITIES_BAM_BAMUTILITIES_H_
#define SRC_UTILITIES_BAM_BAMUTILITIES_H_

#include <stdint.h>

#include <string>
#include <vector>

#include "outsources/samtools/bam.h"

#include "dataStructures/alignment.h"

using std::string;
using std::vector;


namespace BamAlignmentConstant {

const unsigned char kBamCoreSize   = 32;
const unsigned char kBamCigarShift = 4;

// cigar operator for bam packed cigar
const unsigned char kBamCmatch     = 0;
const unsigned char kBamCins       = 1;
const unsigned char kBamCdel       = 2;
const unsigned char kBamCrefSkip   = 3;
const unsigned char kBamCsoftClip  = 4;
const unsigned char kBamChardClip  = 5;
const unsigned char kBamCpad       = 6;
} // namespace BamAlignmentConstant

namespace BamUtilities {

bool ReplaceHeaderSoText(bam_header_t* const header);
bool IsFileSorted(const bam_header_t* const header);

// Given sequence, generate bam-format encoded sequence 
// and store it in encodedSequence
void EncodeQuerySequence(string& encodedSequence, const string& sequence);


// Given aligned reference and query sequences,
// generate bam-foramt packed cigar and store it in packed_cigar
bool GetPackedCigar( 
	vector<uint32_t>& packed_cigar, 
	const string& reference,
	const string& query,
	const uint32_t& query_begin,
	const uint32_t& query_end,
	const uint32_t& read_length);

void ConvertAlignmentToBam1(const Alignment& al,
                            const bam1_t& original_record,
			    bam1_t* new_record);

bool AppendReferenceSequence(const char** names,
                             const uint32_t* lens,
			     const char** md5s,
                             const int& n_sequences,
			     bam_header_t* const header);
} // namespace BamUtilities

#endif // SRC_UTILITIES_BAMUTILITIES_H_
