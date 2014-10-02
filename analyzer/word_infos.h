/**
 * @file word_infos.h
 * @brief Contains declarations of WordInfos' functions.
 */

#ifndef WORD_INFOS_HPP
#define WORD_INFOS_HPP

#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct WordInfos
 * @brief This struct contains information about normal forms of the word (form
 *        and grammar info) and grammar info of the analyzed word.
 */
struct WordInfos;


/**
 * @brief Creates new WordInfos array by size.
 * @param max_size Amount of elements, which can be added to the WordInfos
 *                 array.
 * @return pointer to WordInfos array
 */
struct WordInfos * infos_new(unsigned int max_size);

/**
 * @brief Destroys WordInfos array.
 * @param wi pointer to WordInfos array
 */
void infos_free(struct WordInfos * wi);

/**
 * @brief Erases all data from WordInfos array (including normal forms, so there
 *        is no need to free() normal form manually).
 * @param wi pointer to WordInfos array
 */
void infos_erase(struct WordInfos * wi);

#ifdef __cplusplus
/**
 * @brief Prepends a word to WordInfos array.
 * @param wi         pointer to WordInfos array
 * @param form       normal form
 * @param n_form_id  grammar type of normal form
 * @param form_id    grammar type of form
 * @param prediction was this information get by prediction or not
 * @return true, if added succesfully
 * @return false, if wi is NULL or array is full
 */
bool infos_prepend_word(struct WordInfos * wi, char * form, unsigned short int n_form_id, unsigned short int form_id, bool prediction = false);
#endif

/**
 * @brief Checks was results get by prediction or not.
 * @param wi pointer to WordInfos array
 * @return is array of predicts or not
 */
bool infos_is_prediction(struct WordInfos * wi);

/**
 * @brief Checks is array full or not.
 * @param wi pointer to WordInfos array
 * @return is array full or not
 */
bool infos_have_prepend_error(struct WordInfos * wi);

/**
 * @brief Returns count of added words.
 * @param wi pointer to WordInfos array
 * @return amount of added forms
 */
int infos_get_size(struct WordInfos * wi);
\
/**
 * @brief Gets normal form.
 * @param wi    pointer to WordInfos array
 * @param id    array index
 * @return normal form
 */
char * infos_get_normal_form(struct WordInfos * wi, unsigned int id);

/**
 * @brief Gets normal form id.
 * @param wi    pointer to WordInfos array
 * @param id    array index
 * @return normal form id
 */
unsigned short int infos_get_normal_form_id(struct WordInfos * wi, unsigned int id);

/**
 * @brief Gets form id.
 * @param wi    pointer to WordInfos array
 * @param id    array index
 * @return form id
 */
unsigned short int infos_get_form_id(struct WordInfos * wi, unsigned int id);

#ifdef __cplusplus
}
#endif

#endif
