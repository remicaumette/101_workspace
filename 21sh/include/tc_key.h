/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tc_key.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:41:08 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 14:17:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TC_KEY_H
# define TC_KEY_H

# define TC_KEY_TAB		{9, 0, 0}
# define TC_KEY_RETURN	{10, 0, 0}

# define TC_CTRL_A		{1, 0, 0}
# define TC_CTRL_B		{2, 0, 0}
# define TC_CTRL_C		{3, 0, 0}
# define TC_CTRL_D		{4, 0, 0}
# define TC_CTRL_E		{5, 0, 0}
# define TC_CTRL_F		{6, 0, 0}
# define TC_CTRL_I		{9, 0, 0}
# define TC_CTRL_J		{10, 0, 0}
# define TC_CTRL_K		{11, 0, 0}
# define TC_CTRL_L		{12, 0, 0}
# define TC_CTRL_M		{13, 0, 0}
# define TC_CTRL_N		{14, 0, 0}
# define TC_CTRL_Q		{17, 0, 0}
# define TC_CTRL_R		{18, 0, 0}

# define TC_KEY_BACKDEL	{127, 0, 0}

# define TC_KEY_UP		{27, 91, 65}
# define TC_KEY_DOWN	{27, 91, 66}
# define TC_KEY_LEFT	{27, 91, 68}
# define TC_KEY_RIGHT	{27, 91, 67}
# define TC_KEY_END		{27, 91, 70}

# define TC_KEY_HOME		{27, 91, 72}

# define TC_CTRL_RIGHT	73895905418011
# define TC_CTRL_LEFT	74995417045787
# define TC_CTRL_UP		{}71696882162459
# define TC_CTRL_DOWN	72796393790235

# define TC_NB_COL			"co"
# define TC_NB_LINE			"li"

# define TC_CLEAR			"cl"
# define TC_CLEAR_TO_END	"ce"

# define TC_DEL				"dc"
# define TC_DEL_LINE		"dl"

# define TC_INSER_START		"im"
# define TC_INSER_STOP		"ei"

# define TC_MOVE_UP			"up"
# define TC_MOVE_DOWN		"do"
# define TC_MOVE_LEFT		"le"
# define TC_MOVE_RIGHT		"nd"
#endif
