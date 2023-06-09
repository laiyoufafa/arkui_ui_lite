/*
 * Copyright (c) 2020-2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef UI_FONT_H
#define UI_FONT_H
#include "font/base_font.h"

namespace OHOS {
class UIFont : public HeapBase {
public:
    UIFont(const UIFont &) = delete;
    UIFont& operator=(const UIFont &) = delete;

    /**
     * @brief judge whether you need shaping for text
     *
     * @param text means input text
     * @param ttfId font index
     * @param script shaping script
     * @param fontId font index
     * @param size font size
     * @return int8_t Shaping mode
     */
    uint8_t GetShapingFontId(char* text, uint8_t& ttfId, uint32_t& script, uint8_t fontId, uint8_t size) const
    {
        return instance_->GetShapingFontId(text, ttfId, script, fontId, size);
    }

    /**
     * @brief Set font id
     *
     * @param fontId
     * @param size
     * @return int8_t
     */
    int8_t SetCurrentFontId(uint8_t fontId, uint8_t size = 0)
    {
        return instance_->SetCurrentFontId(fontId, size);
    }

    /**
     * @brief Get width of the letter
     *
     * @param unicode: [in] unicode or glyph index according to isGlyph param
     * @param shapingId: [in]
     * @return uint16_t: the letter width
     */
    uint16_t GetWidth(uint32_t unicode, uint8_t shapingId);

    uint16_t GetWidthSpannable(uint32_t unicode, uint8_t fontId, uint8_t size);

    /**
     * @brief Get height for specific font
     *
     * @return uint16_t
     */
    uint16_t GetHeight()
    {
        return instance_->GetHeight();
    }

    uint16_t GetHeightSpannable(uint8_t fontId, uint8_t size);

    /**
     * @brief Get the font weight
     * @param fontId
     * @return uint8_t: fontWeight
     */
    uint8_t GetFontWeight(uint8_t fontId)
    {
        return instance_->GetFontWeight(fontId);
    }

    /**
     * @brief Get font header
     *
     * @param fontHeader
     * @return int8_t
     */
    int8_t GetCurrentFontHeader(FontHeader& fontHeader)
    {
        return instance_->GetCurrentFontHeader(fontHeader);
    }

    /**
     * @brief Get font id
     *
     * @param name
     * @param size
     * @return uint8_t
     */
    uint8_t GetFontId(const char* name, uint8_t size = 0)
    {
        return instance_->GetFontId(name, size);
    }

    /**
     * @brief Set the cache start address
     *
     * @param psramAddr
     * @param psramLen
     */
    void SetPsramMemory(uintptr_t psramAddr, uint32_t psramLen)
    {
        instance_->SetPsramMemory(psramAddr, psramLen);
    }

    /**
     * @brief Get bitmap for specific unicode
     *
     * @param unicode
     * @return uint8_t*
     */
    uint8_t* GetBitmap(uint32_t unicode, GlyphNode& glyphNode, uint8_t shapingFont);

    uint8_t* GetBitmapSpannable(uint32_t unicode, GlyphNode& glyphNode, uint8_t fontId, uint8_t size);

    /**
     * @brief Indicates whether the current font library is a vector font library.
     * @return uint8_t: 0 BitmapFont  1 VectorFont
     */
    bool IsVectorFont()
    {
        return instance_->IsVectorFont();
    }

    /**
     * @brief Get current font id
     *
     * @return uint8_t
     */
    uint8_t GetCurrentFontId()
    {
        return instance_->GetBaseFontId();
    }

    int8_t SetCurrentLangId(uint8_t langId)
    {
        return instance_->SetCurrentLangId(langId);
    }

    uint8_t GetCurrentLangId() const
    {
        return instance_->GetCurrentLangId();
    }

    int8_t GetDefaultParamByLangId(uint8_t langId, LangTextParam** pParam) const
    {
        return instance_->GetDefaultParamByLangId(langId, pParam);
    }

    int8_t GetTextUtf8(uint16_t textId, uint8_t** utf8Addr, uint16_t& utf8Len) const
    {
        return instance_->GetTextUtf8(textId, utf8Addr, utf8Len);
    }

    uint8_t GetFontTtfId(uint8_t fontId, uint8_t size) const
    {
        return instance_->GetFontTtfId(fontId, size);
    }

    int32_t OpenVectorFont(uint8_t ttfId)
    {
        return instance_->OpenVectorFont(ttfId);
    }

    const UITextLanguageFontParam* GetFontInfo(uint8_t fontId) const
    {
        return instance_->GetFontInfo(fontId);
    }

    int8_t SetFontPath(const char* dpath, const char* spath)
    {
        return instance_->SetFontPath(dpath, spath);
    }

    int8_t GetFontVersion(char* dVersion, uint8_t dLen, char* sVersion, uint8_t sLen) const
    {
        return instance_->GetFontVersion(dVersion, dLen, sVersion, sLen);
    }

    uint8_t RegisterFontInfo(const char* ttfName, uint8_t shaping = 0)
    {
        return instance_->RegisterFontInfo(ttfName, shaping);
    }

    uint8_t RegisterFontInfo(const UITextLanguageFontParam* fontsTable, uint8_t num)
    {
        return instance_->RegisterFontInfo(fontsTable, num);
    }

    uint8_t UnregisterFontInfo(const char* ttfName)
    {
        return instance_->UnregisterFontInfo(ttfName);
    }

    uint8_t UnregisterFontInfo(const UITextLanguageFontParam* fontsTable, uint8_t num)
    {
        return instance_->UnregisterFontInfo(fontsTable, num);
    }

    int8_t GetTextParam(uint16_t textId, UITextLanguageTextParam& param) const
    {
        return instance_->GetTextParam(textId, param);
    }

    int8_t GetWildCardStaticStr(uint16_t textId, UITextWildcardStaticType type,
        uint8_t** strAddr, uint16_t& strLen) const
    {
        return instance_->GetWildCardStaticStr(textId, type, strAddr, strLen);
    }

    int8_t GetCodePoints(uint16_t textId, uint32_t** codePoints, uint16_t& codePointsNum) const
    {
        return instance_->GetCodePoints(textId, codePoints, codePointsNum);
    }

    static UIFont* GetInstance();
    void SetFont(BaseFont* font);

    void SetFontFileOffset(uint32_t offset)
    {
        instance_->SetFontFileOffset(offset);
    }

    uint16_t GetHeight(uint32_t unicode, uint8_t fontId)
    {
        return instance_->GetHeight(unicode, fontId);
    }

    virtual uint16_t GetOffsetPosY(const char* text, uint16_t lineLength, bool& isAllEmoji, uint8_t fontSize)
    {
        return instance_->GetOffsetPosY(text, lineLength, isAllEmoji, fontSize);
    }

    virtual uint16_t GetLineMaxHeight(const char* text, uint16_t lineLength, uint8_t fontId,
                                      uint16_t letterIndex, SizeSpan* sizeSpans);
    bool IsEmojiFont(uint8_t fontid)
    {
        return instance_->IsEmojiFont(fontid);
    }
private:
    UIFont();
    /**
     * @brief Destroy the UIFontFactor object
     *
     */
    ~UIFont();

    BaseFont* instance_;
    BaseFont* defaultInstance_;
    static bool setFontAllocFlag_;
};
} // namespace OHOS
#endif
