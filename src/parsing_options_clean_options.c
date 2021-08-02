#include "prototypes.h"

void	clean_options(t_ls *ls)
{
	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
	{
		if (!is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED)
			|| !is_option_activated(ls, FL_LONG_PRINTING))
			deactivate_option(ls, FL_USE_TIME_FILE_CREATION);
	}
	if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
	{
		if (!is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED)
			|| !is_option_activated(ls, FL_LONG_PRINTING))
			deactivate_option(ls, FL_USE_TIME_LAST_ACCESS);
	}
	if (is_option_activated(ls, FL_DISPLAY_UID_GID))
		add_option_from_flag(ls, FL_LONG_PRINTING);
}
