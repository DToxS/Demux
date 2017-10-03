//
//  DGEIlluminaFASTQSequence.hpp
//  FASTQ-Sequence-Parser
//
//  Created by Yuguang Xiong on 5/4/17.
//  Copyright © 2017 Yuguang Xiong. All rights reserved.
//

#ifndef DGEIlluminaFASTQSequence_hpp
#define DGEIlluminaFASTQSequence_hpp

#include <vector>
#include "IlluminaFASTQSequence.hpp"

namespace hts
{

class DGEIlluminaFASTQSequence : public IlluminaFASTQSequence
{
protected:
    
    // Well barcode of DGE FASTQ sequence produced by Illumina.
    static const LineType well_barcode_line {Sequence};
    static const std::size_t well_barcode_beg_pos {0}, well_barcode_end_pos {5};

    // UMI barcode of DGE FASTQ sequence produced by Illumina.
    static const LineType umi_barcode_line {Sequence};
    static const std::size_t umi_barcode_beg_pos {6}, umi_barcode_end_pos {15};

    // Well barcode.
    std::string well_barcode;

    // UMI barcode.
    std::string umi_barcode;

protected:

    // Set the group ID of FASTQ sequence using sequence information.
    virtual void setGroupId() override;

    void setBarcode()
    {
        well_barcode = lines[Sequence].substr(well_barcode_beg_pos, well_barcode_end_pos-well_barcode_beg_pos+1);
        umi_barcode = lines[Sequence].substr(umi_barcode_beg_pos, umi_barcode_end_pos-umi_barcode_beg_pos+1);
    }

public:
    
    DGEIlluminaFASTQSequence();
    
    // parse_seq is defaulted to true for the parsing of IlluminaFASTQSequence.
    DGEIlluminaFASTQSequence(const FASTQSequenceLines& lines, bool parse_seq=true, bool parse_seq_id_level_1=false, bool parse_seq_id_level_2=false, bool flush_ostream=false);
    
    // parse_seq is defaulted to true for the parsing of IlluminaFASTQSequence.
    DGEIlluminaFASTQSequence(FASTQSequenceLines&& lines, bool parse_seq=true, bool parse_seq_id_level_1=false, bool parse_seq_id_level_2=false, bool flush_ostream=false);

    // parse_seq is defaulted to true for the parsing of IlluminaFASTQSequence.
    DGEIlluminaFASTQSequence(const std::string& line1, const std::string& line2, const std::string& line3, const std::string& line4, bool parse_seq=true, bool parse_seq_id_level_1=false, bool parse_seq_id_level_2=false, bool flush_ostream=false);

    // parse_seq is defaulted to true for the parsing of IlluminaFASTQSequence.
    DGEIlluminaFASTQSequence(std::string&& line1, std::string&& line2, std::string&& line3, std::string&& line4, bool parse_seq=true, bool parse_seq_id_level_1=false, bool parse_seq_id_level_2=false, bool flush_ostream=false);

    DGEIlluminaFASTQSequence(const IlluminaFASTQSequence& seq);

    DGEIlluminaFASTQSequence(IlluminaFASTQSequence&& seq);

    DGEIlluminaFASTQSequence(const FASTQSequence& seq, bool parse_seq_id_level_1=false, bool parse_seq_id_level_2=false);

    DGEIlluminaFASTQSequence(FASTQSequence&& seq, bool parse_seq_id_level_1=false, bool parse_seq_id_level_2=false);

    DGEIlluminaFASTQSequence(const DGEIlluminaFASTQSequence& seq);
    
    DGEIlluminaFASTQSequence(DGEIlluminaFASTQSequence&& seq);

    virtual ~DGEIlluminaFASTQSequence() noexcept;
    
    DGEIlluminaFASTQSequence& operator=(const DGEIlluminaFASTQSequence& seq);
    
    DGEIlluminaFASTQSequence& operator=(DGEIlluminaFASTQSequence&& seq);
    
    // Retrieve the well barcode of DGE FASTQ sequence.
    const std::string& getWellBarcode() const
    {
        return well_barcode;
    }

    // Retrieve the well barcode of DGE FASTQ sequence.
    std::string& getWellBarcode()
    {
        return well_barcode;
    }

    // Retrieve the UMI barcode of DGE FASTQ sequence.
    const std::string& getUMIBarcode() const
    {
        return umi_barcode;
    }

    // Retrieve the UMI barcode of DGE FASTQ sequence.
    std::string& getUMIBarcode()
    {
        return umi_barcode;
    }
};

using DGEIlluminaFASTQSequences = std::vector<DGEIlluminaFASTQSequence>;

}

#endif /* DGEIlluminaFASTQSequence_hpp */
