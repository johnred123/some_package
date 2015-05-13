
#include "package_link_list.h"

/*
 * 
 */
package_slink_list_node_t *package_slink_list_add(package_slink_list_node_t *node)
{
    package_slink_list_node_t *temp_node = (package_slink_list_node_t*)malloc(sizeof(package_slink_list_node_t));;
    if(node == NULL){ /* create a New header */
        if(temp_node){
            memset(temp_node, 0x00, sizeof(package_slink_list_node_t));
            return temp_node;
        }else{
            fprintf(stderr, "can't malloc memorys\r\n");
            return NULL;
        }
    }else{
        node->next_node = temp_node;
    }
}

package_slink_list_node_t *package_slink_list_create(void)
{
    return package_slink_list_add(NULL);
}

package_slink_list_node_t *package_slink_list_delect(package_slink_list_node_t *node)
{
}
